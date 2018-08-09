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
		void spl_Makeloop(int position);
		bool isThereLoop();
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
	cout<<"I am here---"<<endl;
	while(head != NULL && count < position-1){
		head = head->next;
		count++;
	}
	if (head != NULL){
		cout<<"Going to add something"<<endl;
		Node *temp = head->next;
		head->next = new Node(value);
		head->next->next = temp;
	}
	else
		cout<<"Head is Null"<<endl;
}

void SLL::printNodes(){
	Node *node = root;
	while(node != NULL){
		cout<<node->data<<endl;
		node = node->next;
	}
}

void SLL::spl_Makeloop(int position){
	Node *head = root;
	int count = 1;
	while(head != NULL && count < position-1){
		head = head->next;
		count++;
	}
	head->next = root;
}
bool SLL::isThereLoop(){
	bool result = false;
	Node *slow = root;
	Node *fast = root;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow){
			result = true;
			break;
		}
	}
	return result;
}

int main(){
	SLL sll;
	sll.appendNode(27);
	sll.appendNode(37);
	sll.addNode(17);
	sll.addNode(7);
	//sll.printNodes();
	sll.insertAt(5,47);
	//sll.insertAt(12,15);
	for (int i = 0; i< 15; i++)
		sll.appendNode(i*(i+1));
	//sll.spl_Makeloop(10);
	if(sll.isThereLoop()){
		cout<<"Found a loop"<<endl;
		return 0;
	}
	else
		cout<<"No loop found"<<endl;
	
	sll.printNodes();
	return 0;
}