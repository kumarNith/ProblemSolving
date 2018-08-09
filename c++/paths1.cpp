#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

// Given a binary tree of integers and target int N, want to have a function
// that outputs the num of the paths from root which sum to N.
//            3
//         2     1
//       1     1    2
// N = 5
// 3-2, 3-1-1
using namespace std;

class Node{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;
        Node(int val){
            data = val;
        }
};

class BST{
    public:
        void insertRight(Node *, int );
        void insertLeft(Node *root, int val);
        void display(Node *);
        int findNuberofPath(Node*, int);
        int findNuberofPathUtil(Node *, int , int );
        
    
};


void BST::insertLeft(Node *root, int val){
    // Assuming my code will ne send NULL root
    
    root->left = new Node(val);
}

void BST::insertRight(Node *root, int val){
    root->right = new Node(val);
    
}

// Todo :: Add variable to count all possible paths

int BST::findNuberofPathUtil(Node *root, int curr_sum, int target){
    int count = 0;
    if(root == NULL || curr_sum + root->data > target)
        return 0;
    if (curr_sum + root->data == target){
        return 1;
    }
    
    count += findNuberofPathUtil(root->left, curr_sum+root->data, target);
    count += findNuberofPathUtil(root->right, curr_sum+root->data, target);
    
    return count;
    
    
}

int BST::findNuberofPath(Node* root, int target){
    
    if(root == NULL)
        return 0;
    int curr_sum = root->data;
        
    int path_l = findNuberofPathUtil(root->left, curr_sum, target);
    int path_r = findNuberofPathUtil(root->right, curr_sum, target);
    
    return path_l+path_r;
}

void BST::display(Node *node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    display(node->left);
    display(node->right);
    

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Node * root = new Node(2);
    BST bst;
    bst.insertLeft(root, 2);
    bst.insertLeft(root->left, 1);
    bst.insertRight(root->left, 1);
    bst.insertRight(root, 1);
    bst.insertRight(root->right, 1);
    bst.insertLeft(root->right, 2);
    
    bst.display(root);cout<<endl;
    cout<<"No of paths exit :"<<bst.findNuberofPath(root, 4)<<endl;
    
    
    return 0;
}