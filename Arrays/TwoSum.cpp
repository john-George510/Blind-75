#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (hashMap.count(complement)) {
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(arr, target);
    cout << "Indices: ";
    for (int index : ans) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}