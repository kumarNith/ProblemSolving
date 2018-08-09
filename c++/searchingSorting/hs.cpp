#include<iostream>
#include<vector>

using namespace std;

void heapSortUtil(vector<int> &arr, int pos, int size){
	int curr = pos;
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	if (size > left && arr[left] < arr[curr])
		curr = left;

	if (size > right && arr[right] < arr[curr])
		curr = right;

	if(pos != curr){
		int temp = arr[curr];
		arr[curr] = arr[pos];
		arr[pos] = temp;
		heapSortUtil(arr, curr, size);
	}


}

void heapSort(vector<int> &arr, int size ){
	for (int i = (size/2)-1;i >=0; i--){
		heapSortUtil(arr, i, size);
	}
}

int main(){
	vector<int> arr = {99,12,3,4,22,44,0,4,11};
	int size = arr.size();//sizeof(arr)/sizeof(arr[0]);
	cout<<"Size is "<<size<<endl;
	heapSort(arr, size);
	for(int i : arr){
		cout<<i<<" ";
	}
	cout<<endl;
}