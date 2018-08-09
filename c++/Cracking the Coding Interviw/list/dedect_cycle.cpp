#include <iostream>
#include <vector>

using namespace std;
struct Node{
	int data;
	Node* next = NULL;
};

bool detectCycle(Node *root){
	if (root == NULL && root->next == NULL)
		return false;
	Node *slowPtr = root;
	Node *fastPtr = root->next->next;
	
	while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL ){
		if(slowPtr == fastPtr)
			return true;
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return false;
}

void displayList(Node* root){
	while (root != NULL){
		cout<<" "<<root->data;
		root = root->next;
	}
}

int main(){
	Node *root = new Node;
	root->data = 1;
	root->next = new Node;
	root->next->data = 2;
	root->next->next = new Node;
	Node *temp = root->next->next;
	root->next->next->data = 3;
	root->next->next->next = new Node;

	root->next->next->next->data = 4;
	root->next->next->next->next = new Node;

	root->next->next->next->data = 5;
	//root->next->next->next->next = temp;
	root->next->next->next->next = NULL;

	cout<<" Does the list has cycle ? : "<<(detectCycle(root) ? "Yes" : "No")<<endl;

   //displayList(root);




}