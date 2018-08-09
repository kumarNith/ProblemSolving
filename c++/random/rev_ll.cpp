/* This program is to reverse a linked list
*/

#include<iostream>
#include<vector>

using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int val){
			data = val;
			next = NULL;
		}
};

class LinkedList{
	Node *head = NULL;
	public:
		void insert( int );
		void reverse();
		void display();


};

void LinkedList::insert(int val){

	if(head == NULL){
		head = new Node(val);
		return;
	}

	Node *temp = head;
	while(temp->next){

		temp = temp->next;
	}
	temp->next = new Node(val);
}

void LinkedList::display(){
	Node *temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void LinkedList::reverse(){
	Node *curr = head;
	Node *prev = NULL;
	Node *next = NULL;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev; // Let head point to the new "head" node


}

int main(){
	LinkedList ll;
	for (int i = 1; i < 11; i++)
		ll.insert(i);
	ll.display();
	ll.reverse();
	ll.display();


}