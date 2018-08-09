#include<iostream>
#include<string>
using namespace std;

class Node{
	public:
	Node *right = NULL;
	Node *left = NULL;
	int  height = 0;
	int data;
	Node(int value){
		data = value;
	}
};

class binaryTree{
	//private
	public:
	//Node* root = NULL;
	Node* insert(Node *root, int data);
	void display(Node *root);
	int balance(Node *rightNode, Node *leftNode);
	
	Node* rightRotate(Node *node);
	Node* leftRotate(Node *node);
	int setHeight(Node *node);
	int getHeight(Node *node);
	
};

Node* binaryTree::rightRotate(Node *node){
	Node *newRoot = node->left;
	node->left = newRoot->right;
	newRoot->right = node;
	node->height = setHeight(node);
	newRoot->height = setHeight(newRoot);
	return newRoot;
}

Node* binaryTree::leftRotate(Node *node){
	Node *newRoot = node->right;
	node->right = newRoot->left;
	newRoot->left = node;
	node->height = setHeight(node);
	newRoot->height = setHeight(newRoot);
	return newRoot;
}

Node * binaryTree::insert(Node *root, int data){
	if(root == NULL)
		return new Node(data);
	else if(root->data < data)
		root->right = insert(root->right, data);
	else if(root->data > data)
		root->left = insert(root->left, data);
	int diff = balance(root->left, root->right);
	if (diff > 1) //left heavy
	{
		if( getHeight(root->left->left) - getHeight(root->left->right)){ //Stright 
			root = rightRotate(root);
		}
		else{ //Double rotate as Zigzack
			root->left = leftRotate(root->left);
			root = rightRotate(root);
			
		}
	}
	if (diff < -1){ // Right heavy
		if(getHeight(root->right->right) > getHeight(root->right->left)){
			root = leftRotate(root);
		}
		else{ //Zigzac; so double rotation
			root->right = rightRotate(root->right);
			root = rightRotate(root);
		}
	}
	return root;
}

int binaryTree::balance(Node *leftNode, Node *rightNode){
	return (getHeight(leftNode) - getHeight(rightNode));
}

int binaryTree::setHeight(Node *node){
	if(node == NULL)
		return -1;
	node->height =  max(setHeight(node->right), setHeight(node->left))+1;
	return node->height;
}
int binaryTree::getHeight(Node *node){
	if (node == NULL)
		return -1;
	return max(getHeight(node->right), getHeight(node->left))+1;
}

void binaryTree::display(Node *root){
	if (root == NULL)
		return;
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
	
}

int main(){
	Node *root = NULL;
	binaryTree bt;
	root = bt.insert(root, 40);
	root = bt.insert(root, 35);
	root = bt.insert(root, 30);
	bt.display(root);
	cout<<endl;
	cout<<root->data<<endl;
	cout<<root->height<<endl;
}