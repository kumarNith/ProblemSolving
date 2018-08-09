/* 
  Min element is 0 and Max is 999
*/
#include<iostream>
#include<string>

using namespace std;

#define MIN 0
#define MAX 999

class Node {
  public:
	int data;
	Node *right = NULL;
	Node *left =  NULL;
	
	Node(int val){
		data = val;
	}

};

class BST{
	Node *head = NULL;
  public:
	bool isBST(Node*);
	bool isBSTUtil(Node*, int, int);
	Node* insert(Node*, int);
	void display(Node*);
	bool find(Node*, int);
	void invert(Node*);
	int height(Node *node);
};



bool BST::isBSTUtil(Node* root, int min, int max){
	if(root == NULL)
		return true;
	// We assumed all nodes are UNIQUE.
	if (root->data > max || root->data < min){
		return false;
	}

	return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
	//return result;
}

bool BST::isBST(Node* root){
	return (isBSTUtil(root, MIN, MAX));
}

Node* BST::insert(Node *node, int val){
	if(node == NULL)
		return new Node(val);
	if(val > node->data)
		node->right = insert(node->right, val);
	else
		node->left = insert(node->left, val);
	return node;

}

void BST::display(Node *node){
	if(node == NULL)
		return;
	display(node->left);
	cout<<node->data<<" ";
	display(node->right);
}

bool BST::find(Node *node, int val){
	if(node == NULL)
		return false;
	if(node->data == val)
		return true;
	bool result = true; 
	if(val > node->data)
		result = result *  find(node->right, val);
	else
		result = result * find(node->left, val);
	return result;

}

int BST::height(Node *node){
	if(node == NULL)
		return -1;
	return max(height(node->right),height(node->left))+1;
}

void BST::invert(Node *node){
	if (node == NULL)
		return;
	Node *temp = node->right;
	node->right = node->left;
	node->left = temp;
	invert(node->left);
	invert(node->right);
}
int main(){

	Node *node = NULL;
	BST bst;
	node = bst.insert(node, 50);node = bst.insert(node, 30);node = bst.insert(node, 70);
	node = bst.insert(node, 40);node = bst.insert(node, 20);
	node = bst.insert(node, 60);node = bst.insert(node, 80);

	//Height 3
	/*node = bst.insert(node, 15);node = bst.insert(node, 25);
	node = bst.insert(node, 35);node = bst.insert(node, 45);node = bst.insert(node, 55);
	node = bst.insert(node, 65);node = bst.insert(node, 75);node = bst.insert(node, 85);
	*/

	
	//node->right->right->data = -10;
	//node->right->data = -10;
	
	
	
	/*cout<<node->data<<endl;
	cout<<node->right->data<<endl;
	cout<<node->left->data<<endl;
	cout<<node->right->right->data<<endl;
	cout<<node->left->left->data<<endl;*/
	
	cout<<"isBST : "<<bst.isBST(node)<<endl;
	cout<<"find : "<<bst.find(node, -820)<<endl;
	cout<<"find(80) : "<<bst.find(node, 80)<<endl;
	cout<<bst.height(node)<<endl;

	cout<<"Going to invert the BST "<<endl;
	bst.invert(node);
	bst.display(node);cout<<endl;

	return 0;

}