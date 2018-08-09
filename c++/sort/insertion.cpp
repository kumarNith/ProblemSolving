#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int> &arr){
	int j;
	int i;
	int key;
	int len = arr.size();
	for (j = 1; j < len;j++){
		 i = j-1;
		 key = arr[j];
		while(i >=0 && arr[i] > key){
			arr[i+1] = arr[i];
			arr[i] = key;
			i--; 
		}

	}

}
void swap(vector<int> &arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(vector<int> &arr, int start, int end){
	if(start >= end)
		return start;
	int pos = start-1;
	int i = start;
	int pivot = arr[end];
	//int len = end-start;
	for (;i < end; i++){
		if (arr[i] < pivot){
			pos++;
			swap(arr, pos, i);
		}
	}
	swap(arr,++pos,end);
	return pos;
}

void quickSortUtil(vector<int> &arr, int start, int end){
	if(start >= end)
		return;
	int pos = partition(arr, start, end);
	//cout<<"**** start is : "<<start<<"**** end is "<<end<<endl;
	quickSortUtil(arr,start,pos-1);
	quickSortUtil(arr,pos+1,end);

}
void quickSort(vector<int> &arr){
	int len = arr.size();
	quickSortUtil(arr,0,len-1);
	
}

vector<int> MergerSort(vector<int> arr(){
	int len = arr.size();
	vector<int> left = {};
	vector<int> right = {};
	if(len <= 0)
		return arr;
	int mid = len/2;
	left = MergerSort(arr[])



}

int main(){
	vector<int> arr = {6,1,2,6,3,88,22,-9,11};
	insertionSort(arr);
	for (int i : arr)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Quick Sort"<<endl;
	arr = {6,1,2,6,3,88,22,-9,11};
	quickSort(arr);
	for (int i : arr)
		cout<<i<<" ";
	cout<<endl;

	cout<<"Merge Sort"<<endl;
	arr = {6,1,2,6,3,88,22,-9,11};
	arr = MergerSort(arr);
	for (int i : arr)
		cout<<i<<" ";
	cout<<endl;


	return 0;

}