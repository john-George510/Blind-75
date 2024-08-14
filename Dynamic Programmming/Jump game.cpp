#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int> &nums)
{
	int n = nums.size();
	vector<bool> dp(n + 1, false);
	dp[0] = true;
	dp[1] = true;

	for (int i = 1; i < n; i++)
	{
		if (dp[i] && nums[i - 1] > 0)
		{
			if ((i + 1 + nums[i - 1]) > n)
			{
				fill(dp.begin() + i + 1, dp.end(), true);
			}
			else
			{
				fill(dp.begin() + i + 1, dp.begin() + i + 1 + nums[i - 1], true);
			}
		}
	}

	return dp[n];
}

int main()
{
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << canJump(nums) << endl;
	return 0;
}