#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> &graph, set<int> &visited, set<int> &recStack, int node, bool &hasCycle)
{
	printf("visited: ");
	for (auto it = visited.begin(); it != visited.end(); it++)
	{
		cout << *it << " ";
	}
	printf("\n");
	if (recStack.find(node) != recStack.end())
	{
		hasCycle = true;
		return;
	}
	if (visited.find(node) != visited.end())
	{
		return;
	}
	visited.insert(node);
	recStack.insert(node);
	for (int i = 0; i < graph[node].size(); i++)
	{
		dfs(graph, visited, recStack, graph[node][i], hasCycle);
	}
	recStack.erase(node);
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
	vector<vector<int>> graph(numCourses);
	set<int> visited;
	set<int> recStack;
	bool hasCycle = false;
	printf("prerequisites.size() = %d\n", prerequisites.size());
	for (int i = 0; i < prerequisites.size(); i++)
	{
		graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
	}
	for(int i = 0; i<numCourses;i++){
		if(visited.find(i) == visited.end()){
			dfs(graph, visited, recStack, i, hasCycle);
			if (hasCycle){
				return false;
			}
		}
	}

	// printf("visited.size() = %d\n", visited.size());

	// for (int i = 0; i < graph.size(); i++)
	// {
	// 	printf("graph[%d]: ", i);
	// 	for (int j = 0; j < graph[i].size(); j++)
	// 	{
	// 		cout << graph[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return true;

	//Topological Sort
	// vector<int> indegree(numCourses,0);

	// for(int i=0;i<numCourses;i++){
	// 	for(int j=0;j<graph[i].size();j++){
	// 		indegree[graph[i][j]]++;
	// 	}
	// }
	// queue<int> q;
	// for(int i=0;i<numCourses;i++){
	// 	if (indegree[i] == 0){
	// 		q.push(i);
	// 	}
	// }
	// vector<int> topo;

	// while(!q.empty()){
	// 	int node = q.front();
	// 	q.pop();
	// 	topo.push_back(node);

	// 	for(auto it: graph[node]){
	// 		indegree[it]--;
	// 		if (indegree[it]==0) q.push(it);
	// 	}
	// }

	// return (topo.size() == numCourses);


	
}

int main()
{
	int numCourses = 2;
	vector<vector<int>> prerequisites = {{0, 1}, {1,0}};
	cout << canFinish(numCourses, prerequisites) << endl;
	return 0;
}