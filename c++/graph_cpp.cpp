#include<iostream>
#include<string>
#include<vector>

using namespace std;

void addEdge(vector<vector<char> > &edges, char src, char dest){
	edges[src].push_back(dest);
	edges[dest].push_back(src);
}

void printNodes(vector<vector<char> > &edges, int nodes){
	//vector<char> visited;
	for(int i = 0; i < nodes; i++){
		for(char node : edges[i]){
			cout<<nodes;
		}
	}
	cout<<
}
int main(){
	int nodes = 6;
	vector<vector<char> > edges;
	addEdge(edges,'a','c');
	addEdge(edges,'a','b');
	addEdge(edges,'a','e');
	addEdge(edges,'e','k');
	addEdge(edges,'b','k');
	addEdge(edges,'b','d');
	addEdge(edges,'c','d');

	printNodes(edges, nodes);

	return 0;
}