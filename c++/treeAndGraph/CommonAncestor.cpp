#include<iostream>
#include<vector>

using namespace std;

class Node{
   public:
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node (int val){
		data = val;
	}
};

class BinaryTree{
  public:
  	void insertLeft(Node* node, int val){
  		node->left = new Node(val);

  	}
  	void insertRight(Node* node, int val){
    	node->right = new Node(val);
  	}
  	Node* findCommonAncestor(Node*, int , int );
  	Node* findCommonAncestorUtil(Node* , int, int);
  	bool findANodeByVal(Node*, 	int);
  	void display(Node*);
};

bool BinaryTree::findANodeByVal(Node* node, int val){
	bool result = false;
	if(node == NULL)
		return false;
	if(node->data == val)
		return true;
	result = findANodeByVal(node->left, val);
	if(!result)
		result = findANodeByVal(node->right, val);

	return result;
}


Node* BinaryTree::findCommonAncestorUtil(Node* node, int d1, int d2){
	if(node == NULL)
		return NULL;
	//cout<<"findCommonAncestor() d1 : "<<d1<<" d2, "<<d2<<" node data is "<<node->data<<endl;
	bool d1Found = findANodeByVal(node->left, d1);
	bool d2Found = findANodeByVal(node->left, d2);
	//cout<<"d1Found : "<<d1Found<<" ,d2Found "<<d2Found<<endl;
	if(d1Found != d2Found)
		return node;
	else if (d1Found){
		return findCommonAncestor(node->left, d1, d2);
	}
	else
		return findCommonAncestor(node->right, d1, d2);

}

Node* BinaryTree::findCommonAncestor(Node* node, int d1, int d2){
	
	// NULL check is doen at findANodeByVal()
	if(findANodeByVal(node, d1) && findANodeByVal(node, d2))
		node = findCommonAncestorUtil(node, d1,d2);
	else
		node = NULL;

	return node;


}

void BinaryTree::display(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}

int main(){
	Node *root = new Node(10);
	BinaryTree bt;
	bt.insertLeft(root, 13);bt.insertRight(root, 8);
	//height 2 
	bt.insertLeft(root->left, 5);bt.insertRight(root->left, 6);
	bt.insertLeft(root->right, 30);bt.insertRight(root->right, 28);

	//height 3 
	bt.insertLeft(root->left->left, 1);bt.insertRight(root->left->left, 0);
	bt.insertLeft(root->left->right, 33);bt.insertRight(root->left->right, 18);
	bt.insertLeft(root->right->left, 133);bt.insertRight(root->right->left, 48);
	bt.insertLeft(root->right->right, 103);bt.insertRight(root->right->right, 458);

	bt.display(root);cout<<endl;

	int d1, d2;
	cout<<"Enter d1"<<endl;
	cin>>d1;
	cout<<"Enter d2"<<endl;
	cin>>d2;
	Node *common = bt.findCommonAncestor(root, d1,d2);
	if(common)
		cout<<"Common ancestor value : "<<common->data;
	else
		cout<<"Values are not present in the BinaryTree";

	return 0;

	
}