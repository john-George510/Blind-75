#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

string findOrder(string words[], int n, int k)
{
		unordered_map<char,vector<char>> graph;
		
		for(int i=0;i<n-1;i++){
			int j = 0;
			while (j < min(words[i].length(), words[i+1].length()) && words[i][j] == words[i+1][j]){
				if (graph.find(words[i][j]) == graph.end()){
					graph[words[i][j]] = vector<char>();
				}
				j++;
			};
			if(j == min(words[i].length(), words[i+1].length())){
				continue;
			}
			graph[words[i][j]].push_back(words[i+1][j]);
		}
		
		printf("\nGraph:\n");
		for(auto it = graph.begin(); it != graph.end(); it++){
			cout << it->first << " -> ";
			for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
				cout << *it2 << " ";
			}
			cout << endl;
		}

		unordered_map<char,int> indegree;
		for(auto it:graph){
			if (indegree.find(it.first) ==indegree.end()){
				indegree[it.first] = 0;
			}
			for(auto ch:it.second){
				indegree[ch]++;
			}
		}

		printf("\nIndegree:\n");
		for(auto it:indegree){
			cout << it.first << "->" << it.second << endl;
		}

		queue<char> q;

		for(auto it: indegree){
			if (it.second == 0){
				q.push(it.first);
			}
		}
		string topo;
		while (!q.empty()){
			char elmt = q.front();
			q.pop();
			topo.append(1, elmt);
			for(char ch:graph[elmt]){
				indegree[ch]--;
				if (indegree[ch] == 0){
					q.push(ch);
				}
			}
		}

		return topo;
}

int main()
{
	string words[] = {"baa", "abcd", "abca", "cab", "cad"};
	int n = 5;
	int k = 4;
	cout << findOrder(words, n, k) << endl;
	return 0;
}