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

class stack{
	public:
		Node *head = NULL;
		//Node *tail = NULL;
		void push(int val);
		void pop();
		void display();
};

void stack::push(int val){
	Node *new_ = new Node(val);
	Node *temp = head;
	new_->next = temp;
	head = new_;
}

void stack::pop(){
	if(head != NULL){
		cout<<"pop : "<<head->value<<endl;
		head = head->next;
	}
}

void stack::display(){
	if(head == NULL){
		cout<<"Stack is empty"<<endl;
		return;
	}
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->value<<endl;
		temp = temp->next;
	}
}
int main(){
	stack s;
	for (int i = 0; i < 10; i++){
		s.push(i*(i+i));		
	}
	//s.push(12);
	//s.pop();
	//s.push(14);
	s.display();
	for (int i = 0; i < 10; i++){
		s.pop();
	}
	cout<<"Print elements"<<endl;
	s.display();
	//s.pop();
	//s.push(14);
	//s.display();
	//s.push(17);
	//s.display();
return 0;
}