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

class stack{
	Node *head = NULL;
	int length = 0;
  public:
	void push(int val);
	void  pop();
	int peek();
	void display();
	void sort();
	bool isEmpty();
};

void stack::push(int val){
	length += 1;

	Node *temp = head;
	head = new Node(val);
	head->next = temp;
}

void stack::pop(){
	if(!length)
		cout<<"Error : Empty stack "<<endl;
	else{
		length -=1;
		Node *temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
}

void stack::display(){
	Node * curr = head;
	while(curr){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int stack::peek(){
	int val;
	if(!length){
		cout<<"The stack is empty "<<endl;
		val = -9999;
	}
	else{
		val = head->data;
	}
	return val;
}

bool stack::isEmpty(){
	bool empty = true;

	if(length)
		empty = false;
	return empty;
}

void stack::sort(){
	if(!length)
		return;

	stack s2;
	
	int tmp; 
	while(!isEmpty()){

		tmp = peek();
		pop();

		while((!s2.isEmpty()) && (s2.peek() > tmp)){
			push(s2.peek());
			s2.pop();
		}
		s2.push(tmp);
	}

	
	while(!s2.isEmpty()){
		push(s2.peek());
		s2.pop();
	}
}

int main(){
	stack s1;
	s1.push(6);s1.push(5);s1.push(2);
	s1.push(8);s1.push(1);s1.push(3);
	s1.display();
	s1.sort();
	s1.display();
}