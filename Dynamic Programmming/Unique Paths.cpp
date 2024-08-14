#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n)
{
	vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1)
			{
				grid[i][j] = 1;
			} else {
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		}
	}
	printf("grid: \n");
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}

	return grid[m][n];
}

int main()
{
	int m = 3, n = 7;
	cout << uniquePaths(m, n) << endl;
	return 0;
}