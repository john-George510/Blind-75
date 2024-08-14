#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
		int n = s.size();
		vector<bool> dp(n + 1, false);
		dp[n] = true;
		for (int i = n - 1; i >= 0; i--)
		{
				for (string word : wordDict)
				{
						int len = word.size();
						if (i + len <= n && s.substr(i, len) == word)
						{
								dp[i] = dp[i] || dp[i + len];
						}
				}
		}
		return dp[0];

}

int main()
{
		string s = "leetcode";
		vector<string> wordDict = {"leet", "code"};
		cout << "Word Break: " << wordBreak(s, wordDict) << endl;
		return 0;
}