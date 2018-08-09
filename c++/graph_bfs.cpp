#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*class Edges
{

};*/

class Node
{
    public:
        char node;
        //Node *adjacenct = NULL;
        vector<Node *> adjacenct;
        Node *next = NULL;
        //Edges *edge = NULL;
        Node(char c){
            node = c;
        }


};
 
class BasicGraph{
    public:
        Node *root = NULL;
        Node *end = NULL;
        void addNode(char node);
        void addEdge(char src, char dest);
        Node* getNode(char node);
        void printNodes();
        void printAll();
        void DFS();
        void DFS_helper(Node *n,vector<char> &visited);
        void BFS();
        void BFS_helper(queue<Node *> &q, vector<char> &visited);
};

void BasicGraph::addNode(char node)
{
    Node *temp = new Node(node);
    if(root == NULL){
        root = temp;
    }
    else{
        end->next = temp;
    }
    end  = temp;
    temp = NULL;

}

Node * BasicGraph::getNode(char node){
    Node *temp = root;
    while(temp != NULL && temp->node != node){
        temp = temp->next;
    }
    return temp;
}

void BasicGraph::addEdge(char s, char d){
    Node *src = getNode(s);
    Node *dest = getNode(d);
    src->adjacenct.push_back(dest);
}

void BasicGraph::printNodes(){
    Node *temp = root;
    while(temp != NULL){
        cout<<temp->node<<" "; 
        temp = temp->next;
    }
    cout<<endl;
    
}

void BasicGraph::printAll(){
    Node *temp = root;
    while(temp != NULL){
        cout<<temp->node<< " adjacent's are ---> ";
        for(Node* n : temp->adjacenct) 
            cout<<n->node<<" ";
        cout<<endl;
        temp = temp->next;
    }
}

void BasicGraph::DFS_helper(Node *n, vector<char> &visited){
    //cout<<"Hello"<<endl;
    if(n == NULL)
        return;
    if(find(visited.begin(),visited.end(),n->node) == visited.end()){
            cout<<n->node<<" ";
            visited.push_back(n->node);
    }
    for(Node *temp : n->adjacenct){
        DFS_helper(temp, visited);
    }
    
}

void BasicGraph::DFS(){
    if (root == NULL)
        return;
    vector<char> visited;
    //cout<<root->node<<";"
    cout<<" i am in BFS()"<<endl;
    DFS_helper(root, visited );
}

void BasicGraph::BFS_helper(queue<Node *> &q, vector<char> &visited){
    while(q.size()){
        // Base case
        Node *temp = q.front();
        q.pop();
        if(find(visited.begin(),visited.end(),temp->node) == visited.end()){
            cout<<temp->node<<" ";
            visited.push_back(temp->node);
        }
        for(Node *adj : temp->adjacenct){
            q.push(adj);
        }
    }
}

void BasicGraph::BFS(){
    if (root == NULL)
        return;
    vector<char> visited;
    queue<Node *> q;
    q.push(root);
    cout<<" i am in BFS()"<<endl;
    BFS_helper(q, visited );
}


int main(){
    BasicGraph graph;
    graph.addNode('a');graph.addNode('b');
    graph.addNode('c');graph.addNode('d');
    graph.addNode('e');graph.addNode('f');
    graph.addNode('g');
    
    graph.addEdge('a','b');
    graph.addEdge('a','c');
    graph.addEdge('a','d');
    graph.addEdge('f','g');
    graph.addEdge('d','e');
    graph.addEdge('d','f');
    graph.addEdge('b','e');
    //graph.printNodes();
    //graph.printAll();
    graph.DFS();
    graph.BFS();
    return 0;
}
