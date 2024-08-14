#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for (int i=1;i<=n;i++){
					if (i%2==1){
							ans[i]=ans[i-1]+1;
					} else {
							ans[i]=ans[i/2];
					}
        }
        return ans;
    }

int main(){
		int n =16;
		vector<int> ans = countBits(n);
		cout << "Number of 1 bits: ";
		for (int i : ans) {
				cout << i << " ";
		}
		cout << endl;
		return 0;
}
