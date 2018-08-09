/*
Reverse a linked list
*/
#include<iostream>


using namespace std;

struct Node{
  int data=0;
  Node *next=NULL;
};

void insert(Node* &root, int data){
   if(root == NULL){
     root = new Node;
     root->data = data;
   }
   else{
     Node *temp = root;
     while(temp->next != NULL){
         temp = temp->next;
  }
   Node *newNode = new Node;
   newNode->data = data;
   temp->next    = newNode; 
   }
}

void displayList(Node* root){
  while (root != NULL){
    cout<<root->data<<" ";
    root = root->next;
  }
  cout<<endl;
}

Node* listReverse(Node* root){

  /* Assumes this condition will not happen
  if(root == NULL)
    return NULL;
  */
  Node *prev = root;
  Node *curr = root->next;
  Node *nxt = root->next;
  root->next = NULL;
  while(curr != NULL){
    //cout<<"****"<<endl;
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }

  //root = prev;

  return prev;


}


int main(){
  Node *root = NULL;
  
  insert(root,1);insert(root,2);insert(root,3);
  insert(root,4);insert(root,5);insert(root,6);
  cout<<root<<endl;
  displayList(root);
  root = listReverse(root);
  cout<<"After list reversal"<<endl;
  cout<<root<<endl;
  displayList(root);
}
