#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
 public:
	char data;
	vector<Node*> adj = {};
	Node(char ch){
		data = ch;
	}
};

class Graph{
	//Node *start = NULL;
	map <char, Node*> gMap;
  public:
	void addNode(char );
	void addNodeAdjacency(char , char );
	int nodeCount();
	void nodeCountHelper(Node* , map<char, int> , int &);
	void displayDFS(char);
	void displayDFS_Util(Node*, map<char, int>);
	void displayBFS(char);
	bool ispathExist(char, char);
	bool doesPathExist(char , char );
	bool doesPathExistUtil(char , Node* , map<char, int> );
	//void displayBFS_Util(Node*, map<char, int>, queue<Node *> );


	/*void displayBFS();
	void displayDFS();
	
	bool ispathExist();
	void deleteAlink();
	void deleteaNode();*/

};

void Graph::addNode(char data){
	gMap[data] = new Node(data);
}

void Graph::addNodeAdjacency(char src , char dest){
	Node* s_adj = gMap.find(src)->second;
	Node* d_adj = gMap.find(dest)->second;
	s_adj->adj.push_back(d_adj);
	d_adj->adj.push_back(s_adj);
}

void Graph::nodeCountHelper(Node* node, map<char, int> visited, int &count){
	visited[node->data] = 1;
	count++;
	for(Node* ele : node->adj){
		// Check whether the node was already visited ?
		if(visited.find(ele->data)->second == 1){
			//cout<<"-* "<<ele->data<<" *-"<<endl;
			continue; // As the node was already visit look the next;
		}
		
		nodeCountHelper(ele, visited, count);
	}
}
int Graph::nodeCount(){
	// I assume 'a' will be always present in the Node for convinence
	map<char, int> visited;
	int count = 0;
    Node* start = gMap.find('a')->second;

    /*if (start == gMap.end())
		return 0;*/

    nodeCountHelper(start, visited, count);

    return count;
}

void Graph::displayDFS_Util(Node* node, map<char, int> visited){
	visited[node->data] = 1;
	cout<<node->data<<" ";
	for(Node* ele : node->adj){
		if(visited.find(ele->data)->second == 1)
			continue;
		displayDFS_Util(ele, visited);
	}
}

void Graph::displayDFS(char ch){
	Node* start = gMap.find(ch)->second;
	map<char, int> visited;
	
	/*if (start == gMap.end())
		return;*/

	displayDFS_Util(start, visited);
	cout<<endl;
}

bool Graph::doesPathExistUtil(char dest,Node* start, map<char, int> visited){
	bool result = false;

	if(start->data == dest){
		cout<<"	Eureka! Found!! *  "<<start->data<<"- dest "<<dest<<endl;
		return true;
	}
	
	for(Node *ele : start->adj){
		if(visited.find(ele->data)->second == 1)
			continue;
		visited[start->data] = 1;
		//cout<<"*  "<<ele->data<<"- dest "<<dest<<endl;
		//return doesPathExistUtil(dest, ele, visited);
		result = doesPathExistUtil(dest, ele, visited);
		if(result == true) // Write a code to change this ugle logic
			break;

	}
	//cout<<"result is "<<result<<endl;
	return result;
}

bool Graph::doesPathExist(char src, char dest){
	Node* start = gMap.find(src)->second;
	map<char, int> visited;

	return doesPathExistUtil( dest, start, visited);

}
/*
void Graph::displayBFS_Util(Node* node, map<char, int> visited, queue<Node *> q){
	visited[node->data] = 1;
	cout<<node->data<<" ";
	for(Node *ele : node->adj){
		if(visited.find(ele->data)->second == 1)
			continue;


	}	


}*/

void Graph::displayBFS(char ch){
	Node* start = gMap.find(ch)->second;
	map<char, int> visited;
	queue<Node *> q;
	visited[start->data] = 1;
	cout<<start->data<<" ";
	q.push(start);

	while(!q.empty()){
		for(Node *ele : q.front()->adj){
			if(visited.find(ele->data)->second == 1)
				continue;
			visited[ele->data] = 1;
			cout<<ele->data<<" ";
			q.push(ele);
		}
		q.pop();
	}
	
	cout<<endl;

}


int main(){

	Graph myGraph;
	myGraph.addNode('a');myGraph.addNode('b');myGraph.addNode('c');
	myGraph.addNode('d');myGraph.addNode('e');myGraph.addNode('f');
	myGraph.addNode('g');myGraph.addNode('h');myGraph.addNode('z');

	myGraph.addNodeAdjacency('a','b');myGraph.addNodeAdjacency('a','c');
	myGraph.addNodeAdjacency('c','d');myGraph.addNodeAdjacency('d','e');
	myGraph.addNodeAdjacency('d','f');//myGraph.addNodeAdjacency('b','z');
	myGraph.addNodeAdjacency('e','h');
	myGraph.addNodeAdjacency('f','g');
	//myGraph.addNodeAdjacency('f','i');
	cout<<"count : "<<myGraph.nodeCount()<<endl;
	myGraph.displayDFS('f');
	myGraph.displayDFS('a');
	cout<<"Does path exits ? : "<<(myGraph.doesPathExist('b','a') ? "Yes":"No")<<endl;
	return 0;
}

