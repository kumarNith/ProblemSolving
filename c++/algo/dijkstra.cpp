#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node;
class Edge{
 public:
	int distance = 0;
	Node* node = NULL;
	Edge(int d, Node* n){
		distance = d;
		node = n;
	}
};

class Node{
 public:
	char data;
	vector<Edge*> adj = {};
	Node(char ch){
		data = ch;
	}
};

class pathDist{
  public:
	int distance = 0;
	Node *node = NULL;
	pathDist(int d, Node* n){
		distance = d;
		node     = n;
	}
};

class Graph{
	map <char, Node*> gMap;

  public:
	void addNode(char );
	void addNodeAdjacency(char , char, int);
	void displayBFS(char);
	bool findShortestPath(char, char);
	void _minHeapifyUtil(vector<pathDist*> &, int , int );
	void _minHeapify(vector<pathDist*> &);
	void _addNode(Edge *,vector<pathDist*> &, int );
	pathDist* _getMin(vector<pathDist *> &);

};

void Graph::_minHeapifyUtil(vector<pathDist*> &minHeap, int pos, int size){
	//cout<<"pos is : "<<pos<<endl;

	int right = pos * 2 + 1;
	int left  = pos * 2 + 2;
	int min   = pos;

	if(left < size && minHeap[min]->distance > minHeap[left]->distance)
		min = left;

	if (right < size && minHeap[min]->distance > minHeap[right]->distance)
		min = right;

	//cout<<"min is "<<min<<" pos is "<<pos<<endl;

	if (min != pos){
		pathDist *temp =  minHeap[pos];
		minHeap[pos] =  minHeap[min];
		minHeap[min] = temp;
		_minHeapifyUtil(minHeap, min, size);
	}
}

void Graph::_minHeapify(vector<pathDist*> &minHeap){
	int size = minHeap.size();
	int n = size/2 - 1;
	for (int i = n; i >= 0; i--){
		_minHeapifyUtil(minHeap, i, size);
	}
}

void Graph::_addNode(Edge *edge,vector<pathDist*> &minHeap, int currDist){
	minHeap.push_back(new pathDist(currDist+edge->distance, edge->node));
	_minHeapify(minHeap);

}

pathDist* Graph::_getMin(vector<pathDist *> &minHeap){
	pathDist* min_ = minHeap[0];
	int len = minHeap.size() - 1;
	//pathDist* temp = minHeap[0];
	minHeap[0] = minHeap[len];
	minHeap[len] = min_;
	minHeap.pop_back();
	_minHeapify(minHeap);
	return min_;
}

//Under Construction
bool Graph::findShortestPath(char src, char dest){
	vector<pathDist*> minHeap;//vector<Node *> minHeap;
	map<char, char> path; //Key:child, value:parent

	Node* s = gMap.find(src)->second;
	minHeap.push_back(new pathDist(0, s));
	path[src] = src;
	while (!minHeap.empty()){
		pathDist *currMin = _getMin(minHeap);
		if(currMin->node->data == dest){
			cout<<"Found the path "<<endl;
			break;
		}
		for (Edge *ele : currMin->node->adj){
			path[ele->node->data] = currMin->node->data;
			_addNode(ele, minHeap, currMin->distance);
		}
	}
	//print the path
	cout<<"src : "<<src<<", dest : "<<dest<<endl;
	char parent = dest;
	while(parent != src){
		parent = path.find(parent)->second;
		cout<<parent<<" ";
	}
	cout<<endl;

}

void Graph::addNode(char data){
	gMap[data] = new Node(data);
}

void Graph::addNodeAdjacency(char src , char dest, int distance){
	Node* s = gMap.find(src)->second;
	Node* d = gMap.find(dest)->second;
	Edge *sd = new Edge(distance, d);
	//Edge *ds = new Edge(distance, s);
	s->adj.push_back(sd);
	//d->adj.push_back(ds);
}

void Graph::displayBFS(char ch){
	Node* start = gMap.find(ch)->second;
	map<char, int> visited;
	queue<Node *> q;
	visited[start->data] = 1;
	cout<<start->data<<" ";
	q.push(start);

	while(!q.empty()){
		for(Edge *ele : q.front()->adj){
			if(visited.find(ele->node->data)->second == 1)
				continue;
			visited[ele->node->data] = 1;
			cout<<ele->node->data<<" ";
			//cout<<ele->node->data<<" , "<<ele->distance<<" - ";
			q.push(ele->node);
		}
		q.pop();
	}
	/*if (start == gMap.end())
		return;*/

	//displayBFS_Util(start, visited, q);
	cout<<endl;

}


int main(){

	Graph myGraph;
	myGraph.addNode('a');myGraph.addNode('b');myGraph.addNode('c');
	myGraph.addNode('d');myGraph.addNode('e');myGraph.addNode('f');
	myGraph.addNode('g');myGraph.addNode('h');myGraph.addNode('i');

	myGraph.addNodeAdjacency('a','b',12);myGraph.addNodeAdjacency('a','c',20);
	myGraph.addNodeAdjacency('c','d',3);myGraph.addNodeAdjacency('d','e',5);
	myGraph.addNodeAdjacency('d','f',1);myGraph.addNodeAdjacency('e','h',7);
	myGraph.addNodeAdjacency('f','g',2);myGraph.addNodeAdjacency('b','i',2);
	myGraph.addNodeAdjacency('i','f',3);myGraph.addNodeAdjacency('h','g',1);
	//cout<<"count : "<<myGraph.nodeCount()<<endl;
	//myGraph.displayDFS('f');
	myGraph.displayBFS('a');

	myGraph.findShortestPath('a', 'g');
	return 0;
}

