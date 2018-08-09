#include<iostream>
#include<vector>

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

class avlTree{
  public:
  	Node* insert(Node*, int);
  	int getHeight(Node*);
  	//int balance(Node* right, Node* left);
  	void display(Node*);
  	int balanceCheck(Node*, Node*);
  	Node* rightRotate(Node*);
  	Node* leftRotate(Node*);
};

//Left Heavy so do right rotate
Node* avlTree::rightRotate(Node* root){
	Node *newRoot = root->left;
	newRoot->right = root;
	root->left = newRoot->right;

}

//Right Heavy so do left rotate
Node* avlTree::leftRotate(Node*root){
	cout<<"leftRotate"<<endl;
	Node *newRoot = root->right;
	newRoot->left = root;
	//root->right = newRoot->left;
	return newRoot;

}

Node* avlTree::insert(Node* node, int val){
	if(node == NULL)
		node =  new Node(val);
	else if (val > node->data)
		node->right = insert(node->right,val);
	else
		node->left = insert(node->left,val);
	//int diff = 0;
	int diff = balanceCheck(node->left, node->right);
	if(diff > 1){
		cout<<"Left Heavy"<<endl;
		//rightRotate
		node = rightRotate(node);
	}
	if(diff < -1){
		cout<<"Right Heavy"<<endl;
		//leftRotate
		node = leftRotate(node);

	}
	//cout<<diff<<endl;
	return node;
}
int avlTree::balanceCheck(Node *left, Node* right){
	return (getHeight(left) - getHeight(right));
}

int avlTree::getHeight(Node* node){
	if (node == NULL)
		return -1;

	return (max(getHeight(node->right), getHeight(node->left))+1);
}

void avlTree::display(Node* node){
	if(node == NULL)
		return;
	display(node->left);
	cout<<node->data<<" ";
	display(node->right);
}

int main(){
	Node* root = NULL;
	avlTree avlT;
	root = avlT.insert(root, 30);
	root = avlT.insert(root, 35);
	root = avlT.insert(root, 40);
	avlT.display(root);
	cout<<endl;
	cout<<avlT.getHeight(root)<<endl;
}