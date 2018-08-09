#include<iostream>
#include<queue>
//#include <limits>
#include <climits>
using namespace std;


struct bstNode
{
    int value;
    bstNode *right;
    bstNode *left;
};


bstNode* createNewNode(int value)
{
    
    bstNode* newNode = new bstNode();
    newNode->value   = value;
    newNode->left    = NULL;
    newNode->right   = NULL;
    //printf("Creating New node for %d \n", value);
    return newNode;
}
bstNode* insert(bstNode *root, int value)
{
    if (root == NULL)
    {
        root = createNewNode(value);
    }
    else if(value <= root->value)
    {
        //root = root->left;
        //root = insert(root, value);
        root->left = insert(root->left, value);
        /*if (root->left != NULL)
            insert(root->left, value);
        else
           root->left = createNewNode(value);*/
    }
    else
    {
        //root = root->right;
        root->right = insert(root->right, value);
        /*if(root->right != NULL)
            insert(root->right, value);
        else
            root->right = createNewNode(value);*/
    }
    return root;
}

bool search(bstNode *root, int value)
{
    if(root == NULL)
        return false;
    else if (value <= root->value)
    {
        if (value == root->value)
            return true;
        root = root->left;
        return search(root, value);
    }
    else
    {
       root = root->right; 
       return search(root, value);
    }
}


bstNode* findMinNode(bstNode* root)
{
    if(root == NULL)
        cout<<"Error, BST is null";
    
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

bstNode* findMaxNode(bstNode* root)
{
    if(root == NULL)
        cout<<"Error, BST is null";
    
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int findMin(bstNode* root)
{
    if(root == NULL)
        cout<<"Error, BST is null";
    
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->value;
}

int findMax(bstNode* root)
{
    if(root == NULL)
        cout<<"Error, BST is null";
    
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->value;
}

int treeHeight(bstNode* root)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (root == NULL)
    {
        return -1;
    }
    leftHeight = treeHeight(root->left);
    rightHeight = treeHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}

void levelOrder(bstNode* root)
{
    if (root == NULL)
        return;
    queue<bstNode *> Q;
    Q.push(root);
    
    while(!Q.empty())
    {
        bstNode *node = Q.front();
        cout<<node->value<<" ";
        if (node->left != NULL)
            Q.push(node->left);
            
        if (node->right != NULL)
            Q.push(node->right);
        Q.pop();
    }
}

void preOrder(bstNode* node)
{
    if(node == NULL)
    {
        return;
    }
    cout<<node->value<<" ";
    preOrder(node->left);
    preOrder(node->right);    
}

void inOrder(bstNode* node)
{
    if(node == NULL)
    {
        return;
    }
    inOrder(node->left);
    cout<<node->value<<" ";
    inOrder(node->right);
}

bool isSubTreeLesser(bstNode* node, int value)
{
    if (node == NULL)
        return true;
    
    if(node->value <= value 
        && isSubTreeLesser(node->left, value) && isSubTreeLesser(node->right, value))
        return true;
    else
        return false;
}

bool isSubTreeGreater(bstNode* node, int value)
{
    if (node == NULL)
        return true;
    if(node->value > value 
        && isSubTreeGreater(node->left, value) && isSubTreeGreater(node->right, value))
        return true;
    else
        return false;
}

bool isBST(bstNode* node)
{
    if (node == NULL)
        return true;
    if(isSubTreeLesser(node->left, node->value) && isSubTreeGreater(node->right, node->value) 
        && isBST(node->left) && isBST(node->right))
    {
        return true;
    }
    else
        return false;
}

bool utilIsBST(bstNode* node, int min, int max)
{
    if(node == NULL)
        return true;
    if (node->value >= min && node->value < max 
        && utilIsBST(node->left, min, node->value) && utilIsBST(node->right,node->value, max ))
        return false;
    else
        return true;
    
}

bool isBST_efficient(bstNode* node)
{
    return utilIsBST(node, INT_MIN, INT_MAX);
}

bstNode* nodeDelete(bstNode* root, int value)
{
    cout<<"nodeDelete() value "<<value<<endl;
    if(root == NULL)
        return root;
    if (root->value > value)
    {
        cout<<"node value "<<root->value<<endl;
        root->left = nodeDelete(root->left, value);
        return root;
    }
    else if (root->value < value)
    {
        cout<<"node value - "<< root->value<<endl;
        root->right = nodeDelete(root->right, value);
        return root;
    }
    else
    {
        cout<<"found the node "<<endl;
        if(root->right == NULL && root->left == NULL)
        {
            cout<<"leaf node"<<endl;
            delete root;
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            cout<<"left node is empty"<<endl;
            bstNode* temp = root->right;
            delete root;
            root = NULL;
            return temp;
        }
        else if (root->right == NULL)
        {
            bstNode* temp = root->left;
            delete root;
            root = NULL;
            return temp;
        }
        else
        {
            root->value = findMin(root->right);
            nodeDelete(root->right, root->value);
            //delete root;
            return root;
        }
    }
}
int main()
{
    bstNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);insert(root, 20);insert(root, 40);insert(root, 70);
    insert(root, 60);insert(root, 80);insert(root, 85);insert(root, 75);  
    insert(root, 65);insert(root, 55);insert(root, 35);insert(root, 25);
    insert(root, 15);insert(root, 10);//insert(root, 5);insert(root, 1);
    printf("Is 80 present in BST : %s \n", search(root,80) ? "Yes":"No");
    printf("Is 200 present in BST : %s \n", search(root,200) ? "Yes":"No");
    //printf("Minimum value in the tree is %d \n", findMin(root));
    cout<<"Minimum value in the tree is   " << findMin(root) << endl;
    cout<<"Maximum value in the tree is   " << findMax(root) << "\n";
    cout<<"Height of the Tree " << treeHeight(root) <<endl;
    cout<<"Breath first Search"<<endl;
    levelOrder(root);
    cout<<endl<<"Depth first Search, PreOrder"<<endl;
    preOrder(root);
    cout<<endl<<"Is BST()? - "<<(isBST(root) ? "Yes":"No")<<endl;
    cout<<"O(n) complexcity Is BST()? - "<<(isBST_efficient(root) ? "Yes":"No")<<endl;
    cout<<endl<<"Depth first Search, InOrder"<<endl;
    inOrder(root);
    cout<<endl<<"Node delete - 65"<<nodeDelete(root, 65)<<endl;
    inOrder(root);
    
    return 0;
}
