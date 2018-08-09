#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Node{
 public:
	int data;
	
	Node(int value){
		data = value;
	}
};

void minHeapifyUtil(vector<Node*> &minHeap, int pos, int size){
	//cout<<"pos is : "<<pos<<endl;

	int right = pos * 2 + 1;
	int left  = pos * 2 + 2;
	int min   = pos;

	if(left < size && minHeap[min]->data > minHeap[left]->data){
		min = left;
	}

	if (right < size && minHeap[min]->data > minHeap[right]->data){
		min = right;
		 
	}

	//cout<<"min is "<<min<<" pos is "<<pos<<endl;

	if (min != pos){
		Node *temp =  minHeap[pos];
		minHeap[pos] =  minHeap[min];
		minHeap[min] = temp;
		minHeapifyUtil(minHeap, min, size);
	}

}

void minHeapify(vector<Node*> &minHeap){
	int size = minHeap.size();
	int n = size/2 - 1;
	for (int i = n; i >= 0; i--){
		minHeapifyUtil(minHeap, i, size);
	}
	
}
void insert(Node* node, vector<Node*> &minHeap){
	minHeap.push_back(node);
	minHeapify(minHeap);
}

void addNode(int value, vector<Node*> &minHeap){
	Node *node = new Node(value);
	insert(node, minHeap);

}
void display(vector<Node*> minHeap){
	for (Node *node : minHeap)
		cout<<node->data<<" ";
	cout<<endl;
}

int getMinNode(vector<Node*> &minHeap){
	int min = minHeap[0]->data;
	int len = minHeap.size();
	Node *temp = minHeap[0];
	minHeap[0] = minHeap[len-1];
	minHeap[len-1] = temp;
	minHeap.pop_back();
	minHeapify(minHeap);
	return min;
}

int main(){
	vector<Node*> minHeap = {};
	addNode(3, minHeap);addNode(30, minHeap);addNode(2, minHeap);
	display(minHeap);
	addNode(1, minHeap);addNode(0, minHeap);
	display(minHeap);
	//insert(Node* node);
	cout<<"min value is : "<<getMinNode(minHeap)<<endl;
	display(minHeap);

}