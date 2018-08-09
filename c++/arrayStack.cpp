#include<iostream>
#include<string>

using namespace std;

class arrayStack{
	public:
		arrayStack(); // constructor
		~arrayStack(); //destructor
		
		void push(int value);
		int pop();
		int peek();
		bool isEmpty();
		void display();
		int* elements;
		int size;
		int capacity;
};

arrayStack::arrayStack(){
	size = 0;
	capacity = 10;
	elements = new int[capacity]();
}

arrayStack::~arrayStack(){
	delete[] elements;
}

bool isEmpty(){
	bool empty = false;
	if(size = 0)
		empty = true;
	return empty;
}
void arrayStack::push(int value){
	if(size >= capacity){
		int *bigger = new int[capacity*2];
		for(int i = 0; i < size; i++)
			bigger[i] = elements[i];
		capacity *= 2;
		delete[] elements;
		elements = bigger;
		elements[size] = value;
	}
	elements[size] = value;
	size++;
}

int arrayStack::pop(){
	if(isEmpty())
		throw "Empty stack";
	else{
		int result = elements[size];
		size--;
	}
	return result;+
}

int arrayStack::peek(){
	if(isEmpty())
		throw " Empty stack";
	return elements(size);
}

void arrayStack::display(){
	for(int i = 0; i < size; i++)
		cout<<elements[size];
	cout<<endl;
}

int main(){
	arrayStack stack;
	for (int i = 0; i < 5; i++)
		stack.push(i*2+1);
	cout<<stack.display();
	cout<<stack.peek()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	for (int i = 2; i < 5; i++)
		stack.push(i*2+2);
}