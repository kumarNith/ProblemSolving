#include<iostream>
#include<unordered_map> 
using namespace std;

struct Node{
	int data = 0;
	Node *next = NULL;
};

void insert(Node* &root, int data){
	if(root == NULL){
		root = new Node;
		root->data = data;
	}
	else {
		Node *temp = root;
		while(temp->next != NULL){
			temp = temp->next;
		}
		Node *newNode = new Node;
		newNode->data = data;
		temp->next = newNode;
	}
}

void removeDuplicatesHelper(Node *node, int data){
	Node *curr = node;
	Node *nxt  = node->next;
	while(nxt != NULL)
		if(nxt->data == data){
			curr->next = nxt->next;
			delete nxt;
			nxt = curr->next;
		}
		else{
			curr = nxt;
			nxt  = nxt->next;
		}

}

/*Complexity is O(n^2) and space complexity is O(1)*/

void removeDuplicates(Node *root){
	if(root == NULL)
		return;
	while(root != NULL){
		removeDuplicatesHelper(root, root->data);
		root = root->next;
	}			
}

/*Complexity is O(n) and space complexity is O(n)*/
void removeDuplicatesUsingMap(Node *root){
	if (root == NULL){
		return;
	}
	unordered_map<int, int> nodeMap;
	Node *curr = root;
	nodeMap[curr->data] = 1;
	Node *nxt = root->next;
	while(nxt != NULL){
		if(nodeMap.find(nxt->data) != nodeMap.end()){
			curr->next = nxt->next;
			delete nxt;
			nxt = curr->next;
		}
		else{
		nodeMap[nxt->data] = 1;
		curr = nxt;
		nxt = nxt->next;
		}
	}		
}


/*Assumes that K will be always less than size of the Node*/
int deleteKthNodeFromLast_Helper(Node *prev ,Node *curr, int k){
	//Node *prev = root;
	int posFromBack = 0;
	//Node *prev = root;
	//Node *curr = root->next;
	if(curr->next != NULL){
		prev = curr;
		curr = curr->next;
		posFromBack = deleteKthNodeFromLast_Helper(prev, curr, k);
	}

    if(k == posFromBack){
    	prev->next = curr->next;
    	delete curr;
    }
    posFromBack++;
    return posFromBack;
}

void deleteKthNodeFromLast(Node *root, int k){
	if (root == NULL)
		return;
	deleteKthNodeFromLast_Helper(root,root, k);
}

void printAll(Node *root){
	Node *temp = root;
	if (temp == NULL){
	    return;
	}
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Node *root = NULL;
	insert(root, 2);insert(root, 3);
	insert(root, 20);insert(root, 20);
	insert(root, 22);insert(root, 20);
	insert(root, 2);insert(root, 1);
	//insert(root, 2);insert(root, 2);insert(root, 2);insert(root, 2);
	cout<<"Orignial list"<<endl;
	printAll(root);
	//cout<<"After removing duplicate"<<endl;
	//removeDuplicates(root);
	//removeDuplicatesUsingMap(root);
	cout<<"After removing 2nd from last"<<endl;
	deleteKthNodeFromLast(root,1);
	printAll(root);
	return 0;
}

