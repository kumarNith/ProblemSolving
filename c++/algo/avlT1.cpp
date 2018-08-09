#include<iostream>
#include<vector>
#include<queue>

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
  	void display1(Node*);
  	int balanceCheck(Node*, Node*);
  	Node* rightRotate(Node*);
  	Node* leftRotate(Node*);
  	void invert(Node *);
};

//Left Heavy so do right rotate
Node* avlTree::rightRotate(Node* root){
	Node *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;	
	return newRoot;
}

//Right Heavy so do left rotate
Node* avlTree::leftRotate(Node*root){
	//cout<<"leftRotate"<<endl;
	Node *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
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
		//cout<<"Left Heavy"<<endl;
		//rightRotate
		if(getHeight(node->left->left) > getHeight(node->left->right))
			node = rightRotate(node);
		else{ //Zigzac so double rotation
			node->left = leftRotate(node->left);
			node = rightRotate(node);
		} 
	}
	if(diff < -1){
		//cout<<"Right Heavy"<<endl;
		//leftRotate
		if(getHeight(node->right->right) > getHeight(node->right->left))
			node = leftRotate(node);
		else{
			node->right = rightRotate(node->right);
			node        = leftRotate(node);
		}
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

void avlTree::display1(Node* node){
	queue<Node*> dispQ;
	dispQ.push(node);
	//cout<<"display1"<<endl;
	while(!dispQ.empty()){
		//cout<<"Here ? "<<endl;
		Node * top = dispQ.front();
		if(top->left)
			dispQ.push(top->left);
		if(top->right)
			dispQ.push(top->right);
		//cout<<"Or Here ? "<<endl;
		cout<<top->data<<" ";
		dispQ.pop();
	}
}

void avlTree::invert(Node* root){
	if(root == NULL)
		return;
	Node *temp = root->right;
	root->right = root->left;
	root->left = temp;
	invert(root->left);
	invert(root->right);
}

int main(){
	Node* root = NULL;
	avlTree avlT;
	for (int i = 1; i < 13;i++){
		root = avlT.insert(root, i);
	}
	
	//cout<<"3** "<<root->data<<endl;
	avlT.display(root);
	cout<<endl;
	avlT.display1(root);
	cout<<endl;
	
	cout<<avlT.getHeight(root)<<endl;
	avlT.invert(root);
	cout<<"After invert"<<endl;
	avlT.display1(root);
	cout<<endl;
	/*
	cout<<"---------------"<<endl;
	cout<<"H - "<<root->data<<endl;
	cout<<"L - "<<root->left->data<<endl;
	cout<<"R - "<<root->right->data<<endl;
	cout<<"L-R - "<<root->left->right->data<<endl;
	cout<<"L-L "<<root->left->left->data<<endl;
	cout<<"R-R - "<<root->right->right->data<<endl;
	cout<<"R-L - "<<root->right->left->data<<endl;
	*/
}