#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
	int m = text1.length();
	int n = text2.length();
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

	printf("dp: ");
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = m - 1; i >= 0; i--)
	{
		// printf("dp %d: ", i);
		// for (int j = 0; j < n + 1; j++)
		// {
		// 	cout << dp[i][j] << " ";
		// }
		// cout << endl;
		for (int j = n - 1; j >= 0; j--)
		{	
			printf("dp %d %d: ", i, j);
			printf("text1[i]: %c, text2[j]: %c\n", text1[i], text2[j]);
			if (text1[i] == text2[j])
			{
				dp[i][j] = dp[i + 1][j + 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	printf("dp: ");
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[0][0];
}

int main()
{
	string text1 = "abcde";
	string text2 = "ace";
	cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;
	return 0;
}