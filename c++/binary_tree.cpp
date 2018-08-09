#include<iostream>
using namespace std;

class Node{
	public:
	Node *right = NULL;
	Node *left = NULL;
	int data;
	Node(int value){
		data = value;
	}
};

class binaryTree{
	//private
	public:
	Node *root = NULL;
	
	void addNode(int value);
	//void binaryTree::displayNodes();
	void display(Node *node);
	void display_max2min(Node *node);
	Node* removeNode(Node *node, int value);
	Node* findMinNode(Node *node);
	void displayNodes(){
		display(root);
		cout<<endl;
		//cout<<"display_max2min"<<endl;
		//display_max2min(root);
		//cout<<endl;
	}
	
};

void binaryTree::addNode(int value){
	if(root == NULL){
		root = new Node(value);
	}
	else{
		Node *temp = root;
		Node *next = NULL;
		while(temp != NULL){
			if(temp->data > value)
				next = temp->left;
			else
				next = temp->right;
			if (next != NULL)
				temp = next;
			else
				break;
		}
		if(temp->data > value)
			temp->left = new Node(value);
		else
			temp->right = new Node(value);
	}
}
/*
void binaryTree::displayNodes(){
	display(root);
}
*/
Node* binaryTree::findMinNode(Node *node){
	
	if(node == NULL)
		return NULL;
	//Node *node = root;
	while(node->left != NULL)
		node = node->left;
	
	return node;
}
Node* binaryTree::removeNode(Node *node, int value){
	if(node == NULL)
		return node;
	if (node->data > value)
		node->left = removeNode(node->left, value);
	else if(node->data < value) 
		node->right = removeNode(node->right, value);
	else{
		if(node->right == NULL && node->left == NULL){
			delete node;
			node = NULL;
			return NULL;
		}
		else if(node->right == NULL){
			Node *temp = node->left;
			delete node;
			node = NULL;
			return temp;	
		}
		else if(node->left == NULL){
			Node *temp = node->right;
			delete node;
			node = NULL;
			return temp;	
		}
		else{
			Node *temp = findMinNode(node->right);
			cout<<"Node data  "<<node->data<<endl;
			cout<<temp->data<<endl;
			int min_data = temp->data;
			//node->right = removeNode(temp, min_data);
			//removeNode(temp, min_data);
			//removeNode(root, min_data); //temp->data
			node->right = removeNode(node->right, temp->data);
			node->data = min_data;
			return node;
		}
	}
}

void binaryTree::display(Node *node){
	if(node != NULL){
		display(node->left);
		cout<<node->data<<" ";
		display(node->right);
	}
}

void binaryTree::display_max2min(Node *node){
	if(node != NULL){
		display_max2min(node->right);
		cout<<node->data<<" ";
		display_max2min(node->left);
	}
}


int main(){
	binaryTree bt;
	bt.addNode(30);
	bt.addNode(20);
	bt.addNode(25);
	bt.addNode(10);
	bt.addNode(15);
	bt.addNode(27);
	bt.addNode(26);
	bt.addNode(28);
	bt.addNode(41);bt.addNode(38);
	bt.addNode(35);
	bt.addNode(34);bt.addNode(36);
	bt.addNode(45);
	bt.addNode(37);
	bt.addNode(33);
	bt.addNode(50);
	bt.addNode(43);
	bt.addNode(44);bt.addNode(42);
	bt.displayNodes();
	//bt.removeNode(bt.root, 35);
	bt.removeNode(bt.root,41);
	/*bt.removeNode(bt.root,34);
	bt.removeNode(bt.root, 10);
	bt.removeNode(bt.root,37);*/
	//bt.removeNode(bt.root, 33);bt.removeNode(bt.root, 50);bt.removeNode(bt.root, 28);
	bt.displayNodes();
	
}