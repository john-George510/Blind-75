#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
	//Greedy method wont work for all cases

	vector<int> dp(amount+1,amount+1);
	dp[0] = 0;

	for(int a = 1;a<amount+1;a++){
		for(int c: coins){
			if (a - c >= 0){
				dp[a] = min(dp[a],1+dp[a-c]);
			}
		}
	}

	if (dp[amount] != amount + 1){
		return dp[amount];
	}	else {
		return -1;
	}

}

int main()
{
	vector<int> coins = {186, 419, 83, 408};
	int amount = 6249;
	cout << "Minimum number of coins needed: " << coinChange(coins, amount) << endl;
	return 0;
}
