#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> hashmap;

	for(int i=0;i<nums.size();i++){
		if (hashmap.find(nums[i])!=hashmap.end()) {
			return true;
		}
		hashmap[nums[i]]=i;
		printf("hashmap[%d]: %d\n", nums[i], hashmap[nums[i]]);
	}
	return false;
}

int main()
{
	vector<int> arr = {1,2,3,1};
	cout << "Contains Duplicate: " << containsDuplicate(arr) << endl;
	return 0;
}