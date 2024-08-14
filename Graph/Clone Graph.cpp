#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
	public:
		int val;
		vector<Node *> neighbors;

		Node() {}

		Node(int _val)
		{
			val = _val;
		}

		Node(int _val, vector<Node *> _neighbors)
		{
			val = _val;
			neighbors = _neighbors;
		}
};

unordered_map<Node*, Node*> clone;
Node *cloneGraph(Node *node)
{

	// if (node == NULL)
	// {
	// 	return NULL;
	// }

	// unordered_map<Node *, Node *> visited;
	// Node *newNode = new Node(node->val);
	// visited[node] = newNode;

	// vector<Node *> neighbors = node->neighbors;
	// for (int i = 0; i < neighbors.size(); i++)
	// {
	// 	Node *neighbor = neighbors[i];
	// 	if (visited.find(neighbor) == visited.end())
	// 	{
	// 		Node *newNeighbor = cloneGraph(neighbor);
	// 		visited[neighbor] = newNeighbor;
	// 		newNode->neighbors.push_back(newNeighbor);
	// 	}
	// 	else
	// 	{
	// 		newNode->neighbors.push_back(visited[neighbor]);
	// 	}
	// }

	// return newNode;

	if (node == NULL){
		return NULL;
	}
	

	if(clone.find(node) != clone.end()){
		return clone[node];
	}

	Node* newNode = new Node(node->val);

	clone[node] = newNode;
	vector<Node*> neighbours = node->neighbors;
	for (int i = 0;i<neighbours.size();i++){
		Node* neighbour = neighbours[i];
		if (clone.find(neighbour) == clone.end()){
			Node* newNeighbour = cloneGraph(neighbour);
			clone[neighbour] = newNeighbour;
			newNode->neighbors.push_back(newNeighbour);
		} else {
			newNode->neighbors.push_back(clone[neighbour]);
		}
	}
	return newNode;

}

int main()
{
	Node *node = new Node(1);
	node->neighbors.push_back(new Node(2));
	node->neighbors.push_back(new Node(4));
	node->neighbors[0]->neighbors.push_back(new Node(1));
	node->neighbors[0]->neighbors.push_back(new Node(3));
	node->neighbors[1]->neighbors.push_back(new Node(1));
	node->neighbors[1]->neighbors.push_back(new Node(3));
	node->neighbors[0]->neighbors[1]->neighbors.push_back(new Node(2));
	node->neighbors[1]->neighbors[1]->neighbors.push_back(new Node(4));

	Node *clonedNode = cloneGraph(node);
	printf("clonedNode: %d\n", clonedNode->val);
	printf("clonedNode->neighbors: ");
	for (int i = 0; i < clonedNode->neighbors.size(); i++)
	{
		printf("%d ", clonedNode->neighbors[i]->val);
	}
	return 0;
}