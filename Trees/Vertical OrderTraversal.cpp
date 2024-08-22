#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<queue>
#include <utility>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val): data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> findVerticalOrder(Node* root) {
    map<int, map<int, vector<int>>> grid;
		vector<vector<int>> result;
		queue<pair<Node*,pair<int,int>>> todo;
		todo.push({root,{0,0}});

		while (!todo.empty()) {
			auto elmnt = todo.front();
			todo.pop();
			Node* temp = elmnt.first;
			int x = elmnt.second.first;
			int y = elmnt.second.second;
			grid[x][y].push_back(temp->data);
			if (temp->left){
				todo.push({temp->left,{x-1,y+1}});
			}
			if (temp->right){
				todo.push({temp->right,{x+1,y+1}});
			}
		}
		// cout<<grid.size()<<endl;
		int i=0;
		for (auto level:grid){
			result.push_back(vector<int>());
			for (auto elmnt:level.second){
				for (auto val:elmnt.second){
					result[i].push_back(val);
				}
			}
			i++;
		}
    // Function implementation goes here
    return result; // Placeholder return statement
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->left->right = new Node(5);
	root->left->left->right->right = new Node(6);
	root->right->left = new Node(9);
	root->right->right = new Node(11);
	root->right->right->left = new Node(10);
	vector<vector<int>> res = findVerticalOrder(root);
	for(auto vec:res){
		for(auto elmt:vec){
			cout << elmt << " ";
		}
		cout << endl;
	}
	return 0;
}