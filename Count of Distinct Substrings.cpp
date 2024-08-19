#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

struct TrieNode{
	bool wordEnd = false;
	unordered_map<char,TrieNode*> children;
};

void insertNode(TrieNode* curr,char& ch){
	if (curr->children[ch] == nullptr){
		TrieNode* newNode = new TrieNode();
		curr->children[ch] = newNode;
	}
}

void createTrieString(TrieNode* root,string& str){
	TrieNode* curr = root;
	for(int i = 0;i<str.size();i++){
		if(curr->children[str[i]] == nullptr){
			TrieNode* newNode = new TrieNode();
			curr->children[str[i]] = newNode;
		}
		curr->children[str[i-1]] 
		createTrieString(curr->children[str[i-1]],)
		// curr = curr->children[ch];
	}
	curr->wordEnd = true;
}

int main(){
	string str = "abab";
	TrieNode* rootNode = new TrieNode();
	createTrieString(rootNode,str);
	TrieNode* curr = rootNode;
	while(!curr->wordEnd){
		for(auto ch:curr->children){
			if (ch.second!=nullptr){
				cout<< ch.first << endl;
				curr = ch.second;
			}
		}
	}

	return 0;
}