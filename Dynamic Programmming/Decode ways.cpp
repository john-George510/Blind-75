#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numDecodings(string s)
{
	int len = s.size();
	vector<int> dp(len + 1);
	dp[0] = 1;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] == '0')
		{
			dp[i + 1] = 0;
		}
		else
		{
			dp[i + 1] = dp[i];
		}
		if(i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')))
		{
			dp[i + 1] += dp[i - 1];
		}
	}

	return dp[len];
}

int main()
{
	string s = "226";
	cout << numDecodings(s) << endl;
	return 0;
}