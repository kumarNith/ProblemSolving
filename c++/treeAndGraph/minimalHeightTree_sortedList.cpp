#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node(int val){
		data = val;
	}
};

class BST{
  public:
	Node* insert(Node*, int );
	void display(Node*);
	Node* insertSortedElement(vector<int>, Node*, int, int);
};

Node* BST::insert(Node *root, int val){

	if(root == NULL){
		root = new Node(val);
		return root;
	}

	if(root){
		if(root->data > val)
			root->left = insert(root->left, val);
		else
			root->right = insert(root->right, val);
	}
	
	return root; 
}

void BST::display(Node* root){
	if(root == NULL){
		//cout<<"Display() - Reached End of the Node "<<endl;
		return;
	}
	cout<<root->data<<" ";
	display(root->left);
	//cout<<root->data<<" "; 
	display(root->right);
	
}

Node* BST::insertSortedElement(vector<int> lst, Node* root, int start, int end){
	
	if(start > end)
		return root;
	
	int mid = start + (end - start)/2;

	root  = insert(root, lst[mid]);
	root  = insertSortedElement( lst, root, start, mid-1);
	root  = insertSortedElement( lst, root, mid+1, end);

	return root;
}

int main(){
	Node *root = NULL;
	BST bst;
	vector<int> lst = {1,2,3,4,5,6,7};
	//bst.insert(root);
	int length = lst.size();
	if(length){
		root = bst.insertSortedElement(lst,root, 0, length-1);
		bst.display(root);
		cout<<endl;
	}
	else{
		cout<<"Empty array "<<endl;
	}
}