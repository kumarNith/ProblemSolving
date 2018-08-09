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

class LinkedList{
    Node* head = NULL;
  public:
    void insert(int val);
    void display();
    Node* findMiddleNode();
    void reverse();
    void rotateBy_K_elements(int);
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

Node* LinkedList::findMiddleNode(){
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    //if(fast)
    //    slow = slow->next; // Total number of node is Odd
    if(fast)
        cout<<"fast is not NULL"<<endl;
    return slow;
}

/* Actual nodes   1, 2, 3, 4, 5, 6, 7
   Reversed nodes 7, 6, 5, 4, 3, 2, 1
*/

void LinkedList::reverse(){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; //Update the header
}

/* Clockwise rotation of K elements
*/

void LinkedList::rotateBy_K_elements(int k){
    Node* curr = head;
    
    if(curr == NULL)
        return;

    for(int count = 1; count < k && curr; count++){
        curr = curr->next;
    }
    Node *newRoot = curr->next; // Todo :: Check what is going on here
    curr->next = NULL;
    curr = newRoot;
    while(curr->next)
        curr = curr->next;
    curr->next = head;
    head = newRoot;

}

int main(){
    LinkedList lst;
    int n;int k;
    cout<<"Enter the n :"<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
        lst.insert(i);
    lst.display();
    Node* mid = lst.findMiddleNode();
    if(mid)
        cout<<mid->data<<endl;
    
    cout<<"Enter the K :"<<endl;
    cin>>k;
    lst.rotateBy_K_elements(k);
    lst.display();
}

