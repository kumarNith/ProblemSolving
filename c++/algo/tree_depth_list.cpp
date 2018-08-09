#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Node{
 public:
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node(int value){
		data = value;
	}
};

class binaryTree{
 public:
	Node* insert(Node* , int);
	void display(Node*);
	void depthWistList(Node *);
	void depthWistListUtil(queue<Node*>);
};

Node * binaryTree::insert(Node *root, int data){
	if(root == NULL)
		return new Node(data);
	else if(root->data < data)
		root->right = insert(root->right, data);
	else if(root->data > data)
		root->left = insert(root->left, data);
	return root;
}

void binaryTree::display(Node *root){
	if (root == NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
	
}

void binaryTree::depthWistListUtil(queue<Node*> lstQ){
	if(lstQ.empty())
		return;
	int siz = lstQ.size();
	//cout<<"depthWistListUtil : "<<siz<<endl;
	list <Node*> lstD;
	for(int i = 0; i < siz; i++){
		Node* top = lstQ.front();
		lstD.push_back(top);
		if (top->left){
			//lstD.push_back(top->left);
			lstQ.push(top->left);
		}
		if(top->right){
			//lstD.push_back(top->right);
			lstQ.push(top->right);
		}

		lstQ.pop();
	}

	cout << "mylist contains:"<<endl;
  	for(list<Node*>::iterator it=lstD.begin(); it != lstD.end(); it++)
    	cout << (*it)->data <<" ";
    cout<<endl;

	depthWistListUtil(lstQ);
}

void binaryTree::depthWistList(Node* root){
	queue<Node*> lstQ;
	lstQ.push(root);
	depthWistListUtil(lstQ);

}

int main(){
	Node *root = NULL;
	binaryTree bt;
	//for (int i = 1; i <11;i++)
	root = bt.insert(root, 4);root = bt.insert(root, 2);root = bt.insert(root, 7);
	root = bt.insert(root, 1);root = bt.insert(root, 3);root = bt.insert(root, 6);
	root = bt.insert(root, 8);
	bt.display(root);cout<<endl;
	bt.depthWistList(root);
}

