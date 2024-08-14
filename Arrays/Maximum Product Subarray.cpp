#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int maxProduct(vector<int>& nums) {
	int prod1=nums[0],prod2=nums[0],result=nums[0];

	for (int i=1;i<nums.size();i++){
		int temp=max(nums[i],max(prod1*nums[i],prod2*nums[i]));
		prod2=min(nums[i],min(prod1*nums[i],prod2*nums[i]));
		prod1=temp;

		result=max(result,prod1);
	}
	return result;
 }

int main(){
	vector<int> arr = {2,3,-2,4};
	cout << "Maximum Product Subarray: " << maxProduct(arr) << endl;
	return 0;
}