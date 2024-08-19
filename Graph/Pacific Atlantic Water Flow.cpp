#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;

void dfs(int r, int c, set<array<int,2>> &visit, int prevHeight, int ROWS, int COLS, vector<vector<int>> &heights){
		if(visit.find({r,c}) != visit.end() || r<0 || c<0 || r==ROWS || c== COLS || heights[r][c] < prevHeight){
			return;
		}
		visit.insert({r,c});
		dfs(r+1,c,visit,heights[r][c],ROWS,COLS,heights);
		dfs(r-1,c,visit,heights[r][c],ROWS,COLS,heights);
		dfs(r,c+1,visit,heights[r][c],ROWS,COLS,heights);
		dfs(r,c-1,visit,heights[r][c],ROWS,COLS,heights);
};


vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{	
	int m = heights.size();
	int n = heights[0].size();
	set<array<int,2>> pac;
	set<array<int,2>> atl;

	
	for(int c=0;c<n;c++){
		dfs(0,c,pac,heights[0][c],m,n,heights);
		dfs(m-1,c,atl,heights[m-1][c],m,n,heights);
	}

	for(int r=0;r<m;r++){
		dfs(r,0,pac,heights[r][0],m,n,heights);
		dfs(r,n-1,atl,heights[r][n-1],m,n,heights);
	}
	
	vector<vector<int>> res;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if (pac.find({i,j})!=pac.end() && atl.find({i,j})!=atl.end()){
				res.push_back({i,j});
			}
		}
	}
	return res;

}

int main()
{
	vector<vector<int>> heights = {{1, 2, 2, 3, 5},
																 {3, 2, 3, 4, 4},
																 {2, 4, 5, 3, 1},
																 {6, 7, 1, 4, 5},
																 {5, 1, 1, 2, 4}};
	vector<vector<int>> res = pacificAtlantic(heights);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}