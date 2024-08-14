#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int maxi=INT_MIN;
        int sum=0;
        for (int i=0;i<n;i++){
            sum+=nums[i];

            if(sum>maxi){
                maxi=sum;
            }

            if (sum<0){
                sum=0;
            }
        }
        return maxi;
    }
int main()
{
	vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
	cout << "Max Subarray Sum: " << maxSubArray(arr) << endl;
	return 0;
}