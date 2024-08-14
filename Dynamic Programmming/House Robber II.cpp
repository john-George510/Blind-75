#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n + 1);
	dp[0] = 0;

	if (n == 1)
	{
		return nums[0];
	}

	//For House Robber II, we can't rob the first and the last house together

	//Case 1: Rob the first house
	dp[1] = nums[0];
	for (int i = 2; i < n; i++)
	{
		//nums[i-1] because nums is 0-indexed
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}

	int ans1 = dp[n - 1];

	//Case 2: Don't rob the first house
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		//nums[i-1] because nums is 0-indexed
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}

	int ans2 = dp[n];

	return max(ans1, ans2);
	
}

int main()
{
	vector<int> nums = {1,2,3,1};
	cout << rob(nums) << endl;
	return 0;
}
