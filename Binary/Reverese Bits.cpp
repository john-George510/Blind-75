#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
		uint32_t ans = 0;
		for (int i=0;i<32;i++){
				ans = ans << 1;
				ans = ans | (n & 1);
				n = n >> 1;
		}
		return ans;
}

int main(){
		uint32_t n = 43261596;
		cout << "Reversed bits: " << reverseBits(n) << endl;
		return 0;
}