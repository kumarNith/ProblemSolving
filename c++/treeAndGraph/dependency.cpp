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
	vector<Node*> myNodes;
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
	void checkForDependency();

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
		
		src->adj.push_back(dest);
		dest->inc.push_back(src);
	}
	else
		cout<<"addlink failed "<<s<<" , "<<d<<endl;
}

void Graph::addNewNode(char ch){
	//cout<<"addNewNode() for "<<ch<<endl;
	Node* new_ = new Node(ch);
	nodeMap[ch] = new_;
	myNodes.push_back(new_);

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

	nodeMap.erase(ch);
	int pos = find(myNodes.begin(), myNodes.end(), node) - myNodes.begin();
	myNodes.erase(myNodes.begin()+pos);

	delete node;
}

void Graph::checkForDependency(){

	int cnt = myNodes.size();
	while(cnt && myNodes.size()){
		for(Node* tmp : myNodes){
			//cout<<"Size of myNodes is "<<myNodes.size()<<endl;
			if(tmp->inc.size() == 0){
				//cout<<"checkForDependency() found "<<tmp->data<<", has no incoming node"<<endl;
				deleteNode(tmp->data);
			}
		}
		cnt--;
	}

	if(myNodes.size())
		cout<<"Can't compile as there is a dependency"<<endl;
	else
		cout<<"Can be complied"<<endl;
	

}

int main(){
	Graph myG;
	myG.addNewNode('a');myG.addNewNode('b');myG.addNewNode('c');
	myG.addNewNode('d');myG.addNewNode('e');myG.addNewNode('f');
	myG.addNewNode('k');
	
	myG.addLink('a','d');myG.addLink('f','b');myG.addLink('b','d');
	myG.addLink('f','a');myG.addLink('d','c');
	myG.addLink('b','k');myG.addLink('k','b');

	myG.checkForDependency();

	return 0;
}


