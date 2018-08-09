#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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

class BSTree{
  public:
	Node* head = NULL;

	void insert(int );
	int height(Node*);
	bool isBST(Node*);
	//void display();

};

void BSTree::insert(int input){
	if(head == NULL){
		head = new Node(input);
	}
	else{
		Node *curr = head;
		Node *prev = head;
		while(curr){
			prev = curr;
			if(input > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}
		if(input > prev->data)
			prev->right = new Node(input);
		else
			prev->left = new Node(input);
	}

}

int BSTree::height(Node *node){
	if(node == NULL)
		return -1;
	return max(height(node->left), height(node->right))+1;
}

bool BSTree::isBST(Node* node)
{
	bool result;
	if (node == NULL)
		return (true);

	bool leftBST  = isBST(node->left);
	bool rightBST = isBST(node->right);

	if (!(leftBST && rightBST))
		return (false);

	return(abs(height(node->left) - height(node->right)) < 2);
}

int main(){
	BSTree bst;
	bst.insert(4);bst.insert(2);bst.insert(6);
	bst.insert(1);bst.insert(3);bst.insert(5);
	bst.insert(7);
	BSTree bst1;
	bst1.insert(4);bst1.insert(2);bst1.insert(6);
	bst1.insert(1);bst1.insert(3);bst1.insert(5);
	bst1.insert(7);bst1.insert(8);bst1.insert(9);
	cout<<"Height of the tree : "<<bst.height(bst.head)<<endl;
	cout<<"bst::IsBST() : "<<bst.isBST(bst.head)<<endl;
	cout<<"bst1::IsBST() : "<<bst1.isBST(bst1.head)<<endl;

	BSTree bst2;
	bst2.insert(3);bst2.insert(1);bst2.insert(2);
	bst2.insert(0);bst2.insert(5);bst2.insert(4);
	cout<<"bst2::IsBST() : "<<bst2.isBST(bst2.head)<<endl;

}