#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	vector<unordered_set<char>> rowSeen(9);
	vector<unordered_set<char>> colSeen(9);
	vector<unordered_set<char>> boxSeen(9);
	for (int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if (board[i][j] == '.'){
				continue;
			}
			int boxNo = 3*(i/3) + j/3;
			if (rowSeen[i].find(board[i][j]) != rowSeen[i].end() ||
					colSeen[j].find(board[i][j]) != colSeen[j].end() ||
					boxSeen[boxNo].find(board[i][j]) != boxSeen[boxNo].end()){
						return false;
			}
			rowSeen[i].insert(board[i][j]);
			colSeen[j].insert(board[i][j]);
			boxSeen[boxNo].insert(board[i][j]);
		}
	}
	return true;
}

int main() {
		vector<vector<char>> board = {
				{'5','3','.','.','7','.','.','.','.'},
				{'6','.','.','1','9','5','.','.','.'},
				{'.','9','8','.','.','.','.','6','.'},
				{'8','.','.','.','6','.','.','.','3'},
				{'4','.','.','8','.','3','.','.','1'},
				{'7','.','.','.','2','.','.','.','6'},
				{'.','6','.','.','.','.','2','8','.'},
				{'.','.','.','4','1','9','.','.','5'},
				{'.','.','.','.','8','.','.','7','9'}
		};
		cout << isValidSudoku(board) << endl;
		return 0;
}