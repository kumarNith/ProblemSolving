#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Node{
  public:
    char data;
    Node *next = NULL;
    Node(char val){
        data = val;
    }
};

class LinkedList{
    Node* head = NULL;
  public:
    void insert(char val);
    void display();
    bool isPalindrome();
    bool isPalindromeUtil(Node* & , Node* & );

    
  
};

void LinkedList::insert(char val){
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

bool LinkedList::isPalindromeUtil(Node* &left, Node* &right){
    bool isPalind = true;
    if(right == NULL){
        return true;
    }

    isPalind = isPalindromeUtil(left, right->next);
    if(!isPalind)
        return isPalind;

    if(left->data != right->data){
        isPalind = false;
    }
    //else
    //    isPalind = false;
    left = left->next;

    return isPalind;
}

bool LinkedList::isPalindrome(){
    Node *left  = head;
    Node *right = head;
    return isPalindromeUtil(left, right);
}


int main(){
    LinkedList lst;
    /*int n;int k;
    cout<<"Enter the n :"<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
        lst.insert(i);
    */
    lst.insert('a');
    lst.insert('m');lst.insert('m');;lst.insert('a');
    lst.insert('y');;lst.insert('e');
    lst.display();
    cout<<"Is Palindrome ? : "<<(lst.isPalindrome() ? "Yes":"No")<<endl;
    

}

