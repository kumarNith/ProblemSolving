#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> &arr, int s , int d){
	if (!arr.size())
		return;
	int temp = arr[s];
	arr[s] = arr[d];
	arr[d] = temp;

}

void bubbleSort(vector<int> &arr){
	int len = arr.size();
	for (int i = 0; i < len; i++){
		for(int j = 0; j < len-i-1;j++){
			if(arr[j] > arr[j+1])
				swap(arr, j, j+1);
		}

	}
}

int main(){
	vector<int> arr = {6,1,2,6,3,88,22,-9,11};
	cout<<"After bubble sort"<<endl;
	bubbleSort(arr);
	for (int i : arr)
		cout<<i<<" ";
	cout<<endl;
}