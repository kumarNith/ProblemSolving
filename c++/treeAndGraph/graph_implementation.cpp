#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<iterator>
#include<queue>
#include<algorithm>

using namespace std;

class Node{
  public:
	char data;
	vector<Node*> adj;
	vector<Node*> inc;
	Node(int val){
		data = val;
	}

	~Node(){
		cout<<"Node "<<data<<", was deleted"<<endl;
	}
};

class Graph{
	vector<Node*> nodes;
	map<char, Node*> nodeMap;
  public:
	void addLink(char, char);
	//void addIncoming(char, char);
	Node* getNode(char);
	void addNewNode(char);
	void display_BFSUtil(queue<Node*> , vector<Node*>);
	void display_BFS(char);
	void deleteNode(char);
	void deleteNodeIncoming(Node*, Node*);
	void deleteNodeAdjcency(Node*, Node*);

};

Node* Graph::getNode(char ch){
	Node* node = NULL;
	//Node* node1 = NULL;
	map<char, Node*>::iterator it;
	//cout<<"***** getNode() ****"<<endl;
	it = nodeMap.find(ch);
	//cout<<" ****** : "<<node1->data<<endl;
	if(it != nodeMap.end()){
		//Check what happens for it->second ??
		//cout<<"Found a node for "<<ch<<endl;
		node = nodeMap.find(ch)->second;
		//cout<<"$$$$ "<<node->data<<endl;
	}
	else
		cout<<"Couldn't find a node for "<<ch<<endl;

	return node;
}

void Graph::addLink(char s, char d){

	Node* src  = getNode(s);
	Node* dest = getNode(d);
	
	if(src != NULL && dest != NULL){
		src = nodeMap.find(s)->second;
		dest = nodeMap.find(d)->second;
		//cout<<" $$$ src data "<<src->data<<endl;
		//cout<<" $$$ dest data "<<dest->data<<endl;
		src->adj.push_back(dest);
		dest->inc.push_back(src);
	}
	else
		cout<<"addlink failed "<<s<<" , "<<d<<endl;
}

void Graph::addNewNode(char ch){
	Node* new_ = new Node(ch);
	nodeMap[ch] = new_;
	nodes.push_back(new_);

}

void Graph::display_BFSUtil(queue<Node*> dispQ, vector<Node*> visited){
	//Node* node;
	static int i = 0;
	//cout<<"display_BFSUtil "<<++i<<endl;
	//static int i = 0;
	if(dispQ.size() == 0)
		return;
	Node* node = dispQ.front();
	cout<<node->data<<" ";
	
	
	for(Node* next : node->adj){
		//cout<<i++<<endl;
		
		if(find(visited.begin(), visited.end(), next) == visited.end()){
			//cout<<"Pushed data : "<<next->data<<endl;
			dispQ.push(next);
			visited.push_back(next);
		}
		/*
		else
			cout<<"Already visited : "<<next->data<<endl;
		*/
		
		//cout<<" visited : "<<node->data<<endl;
		//dispQ.push(next);
	}
	dispQ.pop();
	//node = dispQ.front();
	display_BFSUtil(dispQ, visited);
}

void Graph::display_BFS(char ch){
	cout<<"display_BFS from "<<ch<<endl;
	queue<Node*> dispQ;
	vector<Node*> visited;
	Node* head  = getNode(ch);
	if(head == NULL){
		cout<<"Couldn't find a for : "<<ch<<endl;
		return;
	}
	visited.push_back(head);
	dispQ.push(head);
	display_BFSUtil(dispQ, visited);
}

void Graph::deleteNodeIncoming(Node* dest, Node* src){
	//dest->inc.pop_back()
	//cout<<"deleteNodeIncoming()"<<endl;
	int pos = find(dest->inc.begin(), dest->inc.end(), src ) - dest->inc.begin();
	if(pos < dest->inc.size())
		dest->inc.erase(dest->inc.begin()+pos);
	else
		cout<<"deleteNodeIncoming - something Wrong"<<endl;
}

void Graph::deleteNodeAdjcency(Node* src, Node* dest){
	//cout<<"deleteNodeAdjcency() "<<endl;
	for(Node* temp : src->adj){
		cout<<temp->data<<" ";
	}
	cout<<endl;
	cout<<"Trying to delete "<<dest->data<<endl;
	int pos = find(src->adj.begin(), src->adj.end(), dest) - src->adj.begin();
	if(pos < src->adj.size())
		src->adj.erase(src->adj.begin()+pos);
	else
		cout<<"deleteNodeAdjcency() - something Wrong. Pos is "<<pos<<endl;
}
void Graph::deleteNode(char ch){
	Node* node  = getNode(ch);
	if(node == NULL){
		cout<<"deleteNode() :: Couldn't find the Node "<<endl;
		return;
	}
	for(Node *next : node->adj){
		deleteNodeIncoming(next, node);
	}
	for(Node *next : node->inc){
		cout<<"*** "<<next->data<<endl;
		deleteNodeAdjcency(next, node);
	}
	cout<<endl;

	int pos = find(myNodes.begin(), myNodes.end(), node) - myNodes.begin();
	myNodes.erase(myNodes.begin()+pos);
	
	nodeMap.erase(ch);
	delete node;
}

int main(){
	Graph myG;
	myG.addNewNode('a');myG.addNewNode('b');myG.addNewNode('c');
	myG.addNewNode('d');myG.addNewNode('e');myG.addNewNode('f');
	myG.addNewNode('k');myG.addNewNode('x');

	//depencies 
	//(a,d) (f,b) (b, d) (f, a) (d, c)
	

	myG.addLink('a','b');myG.addLink('a','c');myG.addLink('a','x');
	myG.addLink('b','d');
	myG.addLink('c','d');myG.addLink('c','e');myG.addLink('c','f');
	
	myG.addLink('e','k');

	myG.addLink('k','f');


	myG.display_BFS('a');
	cout<<endl;
	//myG.display_BFS('b');
	cout<<endl;
	myG.deleteNode('c');
	myG.display_BFS('a');
	cout<<endl;

	myG.addLink('d','e');	
	myG.display_BFS('a');
	cout<<endl;
	return 0;
}


