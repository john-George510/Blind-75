#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int l=0;
	int r=1;
	int maxP=0;
	while(r<prices.size()){
		if (prices[l]<prices[r]){
			int diff=prices[r]-prices[l];
			maxP=max(maxP,diff);
		} else{
			l=r;
		}
		r++;
	}
	return maxP;
}

int main()
{
	vector<int> arr = {7,6,4,3,1};
	cout << "Max Profit: " << maxProfit(arr) << endl;
	return 0;
}