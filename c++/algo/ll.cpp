#include<iostream>

using namespace std;

class Node{
  public:
   int data;
   Node *next = NULL;
   Node(int value){
      data = value;
   }
};

class List{
  public:
	Node *root = NULL;

    //List();
	void addNode( int data);
	void display();
	void delete_(int value);

};
/*
List::List(){
	root = new Node;

}*/
void List::addNode( int data){
	if(root == NULL){
		root = new Node(data);
	}
	else{
		Node *node = root;
		while(node->next != NULL){
			node = node->next;
		}
		node->next = new Node(data);
	}


}

void List::display(){
	Node *node = root;
	cout<<"List display : ";
	while(node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

void List::delete_(int value){
	Node *curr = root;
	Node *prev = NULL;

	if (root == NULL)
		return;
	else{
		while(curr != NULL){
			if (curr->data == value){
				if(curr == root){
					root = root->next;
					//cout<<"deleting the root node"<<endl;
				}
				else
					prev->next = curr->next;
				delete curr;
				curr = NULL;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}

}

int main(){
	List lst;
	lst.addNode(1);lst.addNode(11);lst.addNode(111);
	lst.display();
	lst.delete_(1);lst.delete_(1);
	lst.display();
	lst.delete_(11);
	lst.display();
	lst.delete_(111);
	lst.display();
}