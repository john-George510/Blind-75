#include <iostream>

using namespace std;

int getSum(int a, int b) {
		while (b != 0) {
				unsigned int carry = (unsigned int)(a & b) << 1;
				a = a ^ b;
				b = carry;
		}
		return a;
}

int main()
{
		int a = 1;
		int b = 2;
		cout << "Sum: " << getSum(a, b) << endl;
		return 0;
}