#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n + 1, 1);
	dp[n] = 0;
	dp[n-1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		int j = i + 1;
		while (j < n)
		{
			// printf("i: %d, j: %d\n", i, j);
			if (nums[i] < nums[j])
			{
				dp[i] = max(dp[i], 1 + dp[j]);
			// 	break;
			}
			// else
			// {
				j++;
			// }
		}
	}
	printf("dp: ");
	int maxSub = 0;
	for (int i = 0; i < n+1; i++)
	{
		cout << dp[i] << " ";
		maxSub = max(maxSub, dp[i]);
	}
	printf("\n");
	return maxSub;
}

int main()
{
	vector<int> nums = {0,1,0,3,2,3};
	cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
}