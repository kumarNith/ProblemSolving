#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include <algorithm>

using namespace std;

class Node{
  public:
	char data;
	vector<Node*> adj = {};
	vector<Node *> incoming ={};
	Node(char val){
		data = val;
	}
};

class Graph{
  public:
  	map<char, Node*> myGraph;
  	void addNode(char);
	void addAdjacency(char, char);
	//addAdjacencyUtil(Node* , Node*)
	//addIncoming(char, char);
	bool isTherePathUtil(char , vector<Node*>& , Node* );
	bool isTherePath(char, char);
	void travelDFS(char);
	void travelBFS(char);
	void travelDFSUtil(Node *, vector<Node*>& );
	void travelBFSUtil(Node *, queue<Node*>& , vector<Node*>& );


};

void Graph::addNode(char ch){
	myGraph[ch] = new Node(ch);
}

void Graph::travelDFSUtil(Node *curr, vector<Node*>& visited){
	if(curr == NULL)
		return;
	for(Node *temp : curr->adj){
		// Check whether this node already visted ? 
		// This check will avoid the infinite loop of visiting the node again again
		if(find(visited.begin(), visited.end(), temp) == visited.end()) {
			visited.push_back(temp);
			travelDFSUtil(temp, visited);
		}
	}
	cout<< curr->data<<" ";

}

void Graph::travelDFS(char start){
	vector<Node*> visited;

	Node *root = myGraph.find(start)->second;
	visited.push_back(root);
	travelDFSUtil(root, visited);
	cout<<endl;
}

void Graph::travelBFSUtil(Node *curr, queue<Node*>& bfs, vector<Node*>& visited){
	if(curr == NULL)
		return;
	cout<<curr->data<<" ";
	bfs.pop();
	for(Node *temp : curr->adj){
		// Check whether this node already visted ? 
		// This check will avoid the infinite loop of visiting the node again again
		if(find(visited.begin(), visited.end(), temp) == visited.end()) {
			visited.push_back(temp);
			//travelBFSUtil(temp, visited);
			bfs.push(temp);
		}
	}
	while(bfs.size()){
		Node *next = bfs.front();
		//bfs.pop();
		travelBFSUtil(next, bfs, visited);
	}
}

void Graph::travelBFS(char start){
	vector<Node*> visited;
	queue<Node*> bfs;
	Node *root = myGraph.find(start)->second;
	visited.push_back(root);
	bfs.push(root);
	travelBFSUtil(root, bfs, visited);
	cout<<endl;
}

void Graph::addAdjacency(char s, char d){
	Node *src  = myGraph.find(s)->second; 
	Node *dest = myGraph.find(d)->second;
	src->adj.push_back(dest);
	
	//Add to incoming list
	dest->incoming.push_back(src);


}

bool Graph::isTherePathUtil(char s, vector<Node*>& visited, Node* dest){
	bool result = false;
	//cout<<"isTherePathUtil() s is "<<s<<" , dest is "<<dest->data<<endl;
	if(s == dest->data)
		return true;
	
	for(Node *inc : dest->incoming){
		if(find(visited.begin(), visited.end(), inc) == visited.end()){
			visited.push_back(inc);
			result = isTherePathUtil(s, visited, inc );
			if(result)
				break;
		}
	}
	return result;

}

bool Graph::isTherePath(char s, char d){
	bool result = false;
	if (myGraph.find(s) == myGraph.end() || myGraph.find(d) == myGraph.end())
		return result;
	Node *src   = myGraph.find(s)->second;
	Node *dest  = myGraph.find(d)->second;
	//cout<<src->data<<" , "<<dest->data<<endl;


	//if (src == myGraph.end() || dest == myGraph.end())
	//	return result;
	vector<Node*> visited;
	visited.push_back(dest);
	result = isTherePathUtil(s, visited, dest);
	return result;
}

//void Graph::
int main(){
	Graph myG;
	myG.addNode('a');myG.addNode('b');
	myG.addNode('c');myG.addNode('d');
	myG.addNode('e');myG.addNode('f');
	myG.addNode('g');
	//myG.addNode(a);
	//myG.addNode(a);myG.addNode(a
	myG.addAdjacency('a','b');myG.addAdjacency('a','c');myG.addAdjacency('a','f');
	myG.addAdjacency('b','d');
	myG.addAdjacency('b','e');
	myG.addAdjacency('c','e');
	myG.travelDFS('a');
	myG.travelBFS('a');
	char s, d;
	cout<<"Enter the source Node : "<<endl;
	cin>>s;
	cout<<"Enter the dest Node : "<<endl;
	cin>>d;
	cout<<(myG.isTherePath(s,d) ? "Yes":"No")<<endl;
	//cout<<(myG.isTherePath('a','g') ? "Yes":"No")<<endl;
}