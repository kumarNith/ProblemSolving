#include<iostream>
#include<vector>

using namespace std;
class Node{
	char data;
	vector<Node*> adj = {};
	Node(char val){
		data = val;
	}
};

class Graph{
	Node* insert(Node*);
	Node* display(Node*);
	bool isTherePath(Node*, char dest);
};

int main(){
	Graph g;
	g.insert('a');
	

}