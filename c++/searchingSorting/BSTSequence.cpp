#include<iostream>
#include<vector>
#include<string>

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
	Node* insert(Node*, int);
	void display(Node*);
	vector<string> Sequence(Node*, string, int, int);
	void weaveUtil(string , string , string , int, vector<string>& );
	vector<string> weave(vector<string> , vector<string> );
	vector<string> weaveAppend(vector<string> , string);
};

Node* BST::insert(Node* node, int data){
	if(node == NULL)
		return new Node(data);
	if(node->data < data)
		node->right = insert(node->right,data);
	else
		node->left = insert(node->left, data);

	return node;

}

void BST::display(Node* node){
	if(node == NULL)
		return;
	display(node->left);
	cout<<node->data;
	display(node->right);
}

void BST::weaveUtil(string str1, string str2, string weav, int size, vector<string> &seq){
	//cout<<"weav : "<<weav<<endl;
	if(!str1.size() && !str2.size()){
		if(weav.size() == size){
			//cout<<weav<<endl;
			seq.push_back(weav);
		}
		return;
	}
	for(int i = 0; i < str1.size(); i++){
		weaveUtil(str1.substr(i+1), str2, weav+str1[i], size, seq);		
	}


	for(int j = 0; j < str2.size(); j++){
		weaveUtil(str1, str2.substr(j+1), weav+str2[j], size, seq);	
	}
}

vector<string> BST::weave(vector<string> left, vector<string> right){
	vector<string> seq;
	if(left.size() & right.size())
	for (string l_str : left){
		for(string r_str : right)
			weaveUtil(l_str, r_str, "", l_str.size()+ r_str.size(), seq);
	}
	else if(left.size() == 0){
		for(string r_str : right)
			weaveUtil("", r_str, "",  r_str.size(), seq);

	}
	else if(right.size() == 0){
		for (string l_str : left)
			weaveUtil(l_str, "", "", l_str.size(), seq);
	}
	return seq;
}

vector<string> BST::weaveAppend(vector<string> seq, string s1){
	vector<string> newStr;
	if(seq.size() == 0){
		newStr.push_back(s1);
		return newStr;
	} 
	for(string str : seq){
		newStr.push_back(s1+str);
	}
	return newStr;
}

vector<string> BST::Sequence(Node *node, string str,int index, int total){
	vector<string> seq;
	//Todo :: When to exit ??
	string s1;
	//cout<<index<<"===> "<<str<<endl;
	if(index == total){
	//	cout<<"str is "<<str<<endl;
	}
	if(node == NULL){
		//cout<<"@@@@ "<<str<<endl;
		return seq;
	}

	vector<string> sLeft, sRight;


	//s1 = str + to_string(node->data);
	s1 = to_string(node->data);
	sLeft = Sequence(node->left, str, index+1, total);
	//cout<<"sLeft : "<<sLeft<<endl;
	sRight = Sequence(node->right, str, index+1, total);
	//cout<<"sRight "<<sRight<<endl;
	
	seq = weave(sLeft , sRight);
	seq = weaveAppend(seq, s1);

	//void weaveUtil(string , string , string , int );

	/*
	cout<<"s1+sLeft+sRight : "<<s1+sLeft+sRight<<endl;
	cout<<"s1+sRight+sLeft : "<<s1+sRight+sLeft<<endl;
	*/
	return seq;
}

int main(){
	Node* node = NULL;
	vector<string> seq;
	BST bst;
	vector<int> arr = {4,2,3,1,6,5,7};
	//vector<int> arr = {2,1,3};
	//vector<int> arr = {3, 2 ,4, 1, 5};
	for (int i: arr){
		node = bst.insert(node, i);
	}
	bst.display(node);
	cout<<endl<<endl;
	seq = bst.Sequence(node,"",1,7);

	for (string str : seq){
		//if(str.size() == 7)
			cout<<str<<endl;
	}
	
}