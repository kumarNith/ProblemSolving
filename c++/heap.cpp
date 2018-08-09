#include<iostream>
#include<string>
#include<vector>

using namespace std;
void printArray(vector<int> &arr);
void maxHeapify(vector<int> &arr, int pos){
	//int root = arr[pos];
	//int left = arr[pos*2+1];
	//int right = arr[pos*2+2];
	//cout<<"pos :"<<pos<<" "<<arr[pos]<<endl;
	if(arr[pos] <  arr[pos*2+1]){
		int temp = arr[pos*2+1];
		arr[pos*2+1] = arr[pos];
		arr[pos] = temp;
	}
	if(arr[pos] <  arr[pos*2+2]){
		int temp = arr[pos*2+2];
		arr[pos*2+2] = arr[pos];
		arr[pos] = temp;
	}
    printArray(arr);
}

void heapSort(vector<int> &arr, int n){
	for (int i = n/2; i >=0; i--){
		maxHeapify(arr, i);
	}
	for(int i = 0; i<=n/2; i++)
	    maxHeapify(arr, i);
}
void printArray(vector<int> &arr){
	for(int i : arr)
		cout<<i<<" ";
	cout<<endl;

}

int main(){
	vector<int> arr = {12,4,5,55,13,6,77,97,5,66,11,53,3,1,19};
	printArray(arr);
	int n = arr.size();
	cout<<"size is "<<n<<endl;
	heapSort(arr, n-1);
	printArray(arr);
	return 0;
}