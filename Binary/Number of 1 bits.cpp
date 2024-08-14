#include <iostream>

using namespace std;

int hammingWeight(int n) {
	int count = 0;
	while (n) {
		count = n % 2;
		n = n / 2;
	}
	return count;
}

int main()
{
	int n = 00000000000000000000000000001011;
	cout << "Number of 1 bits: " << hammingWeight(n) << endl;
	return 0;
}