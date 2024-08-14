#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = nums[0];
	for (int i = 2; i <= n; i++)
	{
		//nums[i-1] because nums is 0-indexed
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}

	return dp[n];
}

int main()
{
	vector<int> nums = {2, 7, 9, 3, 1};
	cout << rob(nums) << endl;
	return 0;
}
