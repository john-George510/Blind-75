#include<vector>
#include<unordered_set>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val): data(val), left(nullptr), right(nullptr) {}
};

vector<int> getInorder(Node* root){
	vector<int> inorder;
	Node* curr = root;
	while(curr != nullptr){
		if (curr->left == nullptr){
			inorder.push_back(curr->data);
			curr = curr->right;
		} else {
			Node* prev = curr->left;
			while (prev->right && prev->right!=curr){
				prev= prev->right;
			}
			if (prev->right == nullptr){
				prev->right = curr;
				curr = curr->left;
			} else {
				prev->right == nullptr;
				inorder.push_back(curr->data);
				curr = curr->right;
			}
		}
	}
	inorder.push_back(curr->data);
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
	vector<int> result = getInorder(root);
	for (int i=0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
	return 0;
}