#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>

using namespace std;

int count = 0;

void dfs(int r, int c, set<array<int,2>> &visited, int ROWS, int COLS, vector<vector<char>>& grid){
	int dr[] = {0, 0, 1, -1};
	int dc[] = {1, -1, 0, 0};
	for(int i = 0; i < 4; i++){
		int newR = r + dr[i];
		int newC = c + dc[i];
		if(newR >= 0 && newR < ROWS && newC >= 0 && newC < COLS && grid[newR][newC] == '1' && visited.find({newR, newC}) == visited.end()){
			visited.insert({newR, newC});
			dfs(newR, newC, visited, ROWS, COLS, grid);
		}
	}
}

void bfs(int r, int c, set<array<int,2>> &visited, int ROWS, int COLS, vector<vector<char>>& grid){
	int dr[] = {0, 0, 1, -1};
	int dc[] = {1, -1, 0, 0};
	queue<array<int,2>> q;
	q.push({r, c});
	visited.insert({r, c});
	while(!q.empty()){
		array<int,2> curr = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int newR = curr[0] + dr[i];
			int newC = curr[1] + dc[i];
			if(newR >= 0 && newR < ROWS && newC >= 0 && newC < COLS && grid[newR][newC] == '1' && visited.find({newR, newC}) == visited.end()){
				visited.insert({newR, newC});
				q.push({newR, newC});
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) {
	int m =  grid.size();
	int n = grid[0].size();
	set<array<int,2>> visited;
	
	int islands = 0;

	for(int r = 0; r < m; r++){
		for(int c = 0; c < n; c++){
			if(grid[r][c] == '1' && visited.find({r,c}) == visited.end()){
				islands++;
				dfs(r, c, visited, m, n, grid);
				// bfs(r, c, visited, m, n, grid);
			}
		}
	}
	return islands;
}

int main(){
	int m = 4, n = 5;
	vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
															 {'1', '1', '0', '0', '0'},
															 {'0', '0', '1', '0', '0'},
															 {'0', '0', '0', '1', '1'}};
	cout << numIslands(grid) << endl;
}