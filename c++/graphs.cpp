#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node{
 public:
	char data;
	vector<Node> adj = NULL;
	Node(char ch){
		data = ch;
	}
};

class Graph{
	//Node *start = NULL;
	map <char, Node*> gMap;
  public:
	void addNode(char data);
	void addNodeAdjacency(char src, char dest);
	/*void displayBFS();
	void displayDFS();
	void nodeCount();
	bool ispathExist();
	void deleteAlink();
	void deleteaNode();*/

};

void Graph::addNode(char data){
	Node* node = Node(data);
	gMap.insert(data,node);
}

void Graph::addNodeAdjacency(char src , char dest){
	vector<Node> s_adj = gMap.find(src)->second;
	vector<Node> d_adj = gMap.find(dest)->second;
	s_adj.push_back(dest);
	d_adj.push_back(src);
}
int main(){
	myGraph = Graph();
	myGraph.addNode('a');
	myGraph.addNode('b');
	myGraph.addNode('c');
	myGraph.addNodeAdjacency('a','b');
	return 0;
}

