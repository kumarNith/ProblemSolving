#include<iostream>
#include<cmath>

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

int listAdditionRevHelper(Node *node){
  int sum = 0;
  static int i = 0;
  if(node == NULL){
    cout<<"Node is NULL"<<endl;
    i = 0;
    return 0;
  }
  
  sum = listAdditionRevHelper(node->next);
  cout<<" is "<<i<< " "<<pow(10, i)<<"node data "<<node->data<<endl;
  sum += pow(10, i) * node->data;
  i++;
  return sum;
}

int listAdditionReverse(Node* one, Node* two){
    int sum = listAdditionRevHelper(one) + listAdditionRevHelper(two);
    return sum;
}

int listAdditionHelper(Node *node){
  int sum = 0;
  int i = 0;
  if(node == NULL){
    return 0;
  }
  while(node != NULL){
    sum += pow(10,i) * node->data;
    node = node->next;
    i++;
  }
  return sum;
}

/* Fist node one's position
   Second node is ten's position
*/
int listAddition(Node* one, Node* two){
    int sum = listAdditionHelper(one) + listAdditionHelper(two);
    return sum;
}

int main(){
  Node *one = NULL;
  Node *two = NULL;
  insert(one,2);insert(one,3);insert(one,7);
  insert(two,3);insert(two,6);insert(two,2);
  cout<<"Sum of two lists : "<<listAddition(one, two)<<endl; // 732 + 263 = 995
  cout<<"Sum of two lists : "<<listAdditionReverse(one, two)<<endl; // 237 + 362 = 599

}
