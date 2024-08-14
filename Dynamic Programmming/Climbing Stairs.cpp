#include <iostream>

using namespace std;

int climbStairs(int n)
{
	int a = 1;
	int b = 1;
	// Current step = previous step + step before previous step
	for (int i = 2; i <= n; i++)
	{
		int temp = a;
		a = a + b;
		b = temp;
	}
	return a;
}

int main()
{
	int n = 5;
	cout << "Number of ways to climb stairs: " << climbStairs(n) << endl;
	return 0;
}