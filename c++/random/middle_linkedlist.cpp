#include<iostream>
#include<vector>

using namespace std;

class Node{
  public:
	int data;
	Node *next = NULL;
	Node(int val){
		data = val;
	}
};

class LinkedList{
	Node* head = NULL;
  public:
	void insert(int val);
	void display();
	Node* findMiddleNode();
};

void LinkedList::insert(int val){
	if(head == NULL)
		head = new Node(val);
	else{
		Node* curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = new Node(val);
	}
}

void LinkedList::display(){
	Node *curr = head;
	while(curr){
		cout<<curr->data;
		curr = curr->next;
	}

	cout<<endl;
}

Node* LinkedList::findMiddleNode(){
	Node *slow = head;
	Node *fast = head;

	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	if(fast)
		slow = slow->next; // Total number of node is Odd
	return slow;
}
int main(){
	LinkedList lst;
	int n = 10;
	for (int i = 1; i <= n; i++)
		lst.insert(i);
	lst.display();
	cout<<lst.findMiddleNode()<<endl;

}