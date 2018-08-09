#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Node{
  public:
    int data;
    Node *next = NULL;
    Node(int val){
        data = val;
    }
};

class LinkedList{
    Node* head = NULL;
  public:
    void insert(int val);
    void display();
    int getTheNumber();
    int getTheNumberUtil(Node*, int& );
    int getTheNumberRev();
    int getTheNumberRevUtil(Node*, int );
  
};

void LinkedList::insert(int val){
    if(head == NULL)
        head = new Node(val);
    else{
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = new Node(val);
    }
}

void LinkedList::display(){
    Node *curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }

    cout<<endl;
}

int LinkedList::getTheNumberUtil(Node *root, int& num){
    if(root == NULL)
        return -1;
    int index = getTheNumberUtil(root->next, num) + 1;
    num += (pow(10, index) * root->data);
    
    return index;
}

// Node will contain the value as 1,2,3 and the value is 123
int LinkedList::getTheNumber(){
    int num = 0;
    if(head == NULL)
        return 0;
    getTheNumberUtil(head, num);
    return num;

}


int LinkedList::getTheNumberUtil1(Node *root, int index, int count){
    if(root == NULL)
        return 0;
    int index = getTheNumberUtil(root->next, num) + 1;
    num += (pow(10, index) * root->data);
    
    return index;
}

// Node will contain the value as 1,2,3 and the value is 123
int LinkedList::getTheNumber1(){
    int num = 0;
    int index = 1; //Index of the node from the begining
    int count = 1; // Total count of the nodes
    if(head == NULL)
        return 0;
    num getTheNumberUtil(head, index, count);
    return num;

}


int LinkedList::getTheNumberRevUtil(Node *root, int index){
    if(root == NULL)
        return 0;
    int num = getTheNumberRevUtil(root->next, index+1);
    //num += (pow(10, index) * root->data);
    cout<<index<<" *";
    num += (pow(10, index) * root->data);
    cout<<num<<" *";
    return num;
}


// Node will contain the value as 1,2,3 and the value is 321
int LinkedList::getTheNumberRev(){
    int num = 0;
    int index = 0;
    if(head == NULL)
        return 0;
    num = getTheNumberRevUtil(head, index);
    cout<<endl;
    return num;

}


int main(){
    LinkedList lst;
    /*int n;int k;
    cout<<"Enter the n :"<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
        lst.insert(i);
    */
    lst.insert(5);lst.insert(0);lst.insert(8);
    lst.display();
    //Node* mid = lst.findMiddleNode();
    //if(mid)
    //    cout<<mid->data<<endl;
    int num1 = lst.getTheNumber();
    cout<<"Fwd : "<<num1<<endl;
    num1 = lst.getTheNumberRev();
    cout<<"Rev : "<<num1<<endl;
    

}

