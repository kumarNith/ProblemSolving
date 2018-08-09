#include<iostream>
using namespace std;
class Node{
	public:
		int value;
		Node *next = NULL;
		Node(int val){
			value = val;
		}
};

class Queue{
	public:
		Node *head = NULL;
		Node *tail = NULL;
		void enQueue(int val);
		void deQueue();
		void displayQ();
};

void Queue::enQueue(int val){
	Node *new_ = new Node(val);
	//cout<<"Inside the Q"<<endl;
	if(head == NULL){
		head = new_;
		tail = new_;
	}
	else{
		//cout<<"Inside the Q - else"<<endl;
		tail->next = new_;
		tail = new_;
	}
}

void Queue::deQueue(){
	if(head != NULL){
		cout<<"deQueue : "<<head->value<<endl;
		head = head->next;
		if(head == NULL){
			tail = NULL;
		}
	}
}

void Queue::displayQ(){
	if(head == NULL){
		cout<<"Q is empty"<<endl;
		return;
	}
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->value<<endl;
		temp = temp->next;
	}
}
int main(){
	Queue q;
	for (int i = 0; i < 10; i++){
		q.enQueue(i*(i+i));		
	}
	q.enQueue(12);
	q.deQueue();
	q.enQueue(14);
	q.displayQ();
	for (int i = 0; i < 10; i++){
		q.deQueue();
	}
	cout<<"Print elements"<<endl;
	q.displayQ();
	q.deQueue();
	//q.enQueue(14);
	q.displayQ();
	q.enQueue(17);
	q.displayQ();
return 0;
}