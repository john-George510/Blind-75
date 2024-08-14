#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> prefix(nums.size(),1);
        // vector<int> suffix(nums.size(),1);
        
        int n=nums.size();
        vector<int> answer(n,1);
		int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
		printf("answer: ");
		for (int index : answer) {
			cout << index << " ";
		}

		int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        // int lr=1;
        // for(int i=1;i<n;i++){
        //     lr=answer[i-1];
        //     answer[i]=nums[i-1]*lr;
		// 	printf("answer[%d]: %d\n", i, answer[i]);
		// 	printf("nums[%d]: %d\n", i, nums[i]);
		// 	printf("lr: %d\n", lr);
        //     // prefix[i]=prefix[i-1]*nums[i-1];
        // }
        // int rt=1;
        // for(int i=1;i<n;i++){
        //     rt=nums[n-i];
        //     answer[n-i-1]=answer[n-i]*rt;
		// 	printf("answer[%d]: %d\n", n-i-1, answer[n-i-1]);
		// 	printf("nums[%d]: %d\n", n-i, nums[n-i]);
		// 	printf("rt: %d\n", rt);
        //     // suffix[n-i-1]=suffix[n-i]*nums[n-i];
        // }
        // for(int i=0;i<n;i++){
        //     answer[i]=prefix[i]*suffix[i];
        // }
        return answer;
    }

int main()
{
	vector<int> arr = {1,2,3,4};
	vector<int> ans = productExceptSelf(arr);
	cout << "Product of Array Except Self: ";
	for (int index : ans) {
		cout << index << " ";
	}
	cout << endl;
	return 0;
}