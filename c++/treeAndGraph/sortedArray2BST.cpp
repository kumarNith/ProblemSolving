#include<iostream>
#include<string>
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
	void display(Node* node){
		if (node == NULL)
			return;
		display(node->left);
		cout<<node->data<<endl;
		display(node->right);
	}
};

Node* sortedArray2BST(int* arr, int start, int end){
	if(start > end){
		return NULL;
	}
	int mid = (start + end)/2;
	Node* node = new Node(arr[mid]);
	node->left  = sortedArray2BST(arr, start, mid-1);
	node->right = sortedArray2BST(arr, mid+1, end);

	return node;

}

int main(){
	int arr[] = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	Node *myNode = sortedArray2BST(arr,0,size-1);
	myNode->display(myNode);
	return 0;
}