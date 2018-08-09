#include <iostream>
using namespace std;
class Node{
	public:
		Node *next = NULL;
		int data;
		Node (int val){
			this->data = val;
		}
};

class SLL{
    private:
        Node *root = NULL;
    public:
    	void appendNode( int value);
    	void addNode(int value);
		void insertAt(int position, int value);
		void partitionByValue(int value);
		void removeNode(int value);
    	void printNodes();
        SLL(){
            cout<<"Class SLL"<<endl;
        }
};
void SLL::appendNode( int value){
	Node *node;
	node = root;
	if(node != NULL){
	    while(node->next != NULL)
		    node = node->next;
		node->next = new Node(value);
	}
	else{
	    addNode(value);
	}
}

void SLL::addNode(int value){
	Node *head;
	head = new Node(value);
	head->next = root;
	root = head;
}

void SLL::insertAt(int position, int value){
	Node *head = root;
	int count = 1;
	while(head != NULL && count < position-1){
		head = head->next;
		count++;
	}
	if (head != NULL){
		Node *temp = head->next;
		head->next = new Node(value);
		head->next->next = temp;
	}
}

void SLL::removeNode(int value){
}

void SLL::partitionByValue(int value){
	Node *head = root;
	while(head != NULL){
		if(head->data < value){
			addNode(head->data);
			
		}
			
	}
	
}

void SLL::printNodes(){
	Node *node = root;
	while(node != NULL){
		cout<<node->data<<endl;
		node = node->next;
	}
}



int main(){
	SLL sll;
	sll.insertAt(5,47);
	for (int i = 0; i< 15; i++){
		if(i%2)
			sll.appendNode(i*(i+1));
		else
			sll.appendNode((-i)*(i+1));
	}
	sll.appendNode(27);
	sll.appendNode(37);
	sll.addNode(17);
	sll.addNode(7);
	sll.printNodes();
	return 0;
}