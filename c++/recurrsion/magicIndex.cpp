#include<iostream>
#include<string>
#include<vector>

using namespace std;

int magic_index(int* arr,int start, int end){
	int index;
	cout<<"start : "<<start<<", end "<<end<<endl;
	if(start > end){
		return -1;
	}

	int mid = (end+start)/2;

	if(arr[mid] == mid){
		return mid;
	}
	else if (arr[mid] > mid){
		index = magic_index(arr, 0, mid-1);
	}
	else
		index = magic_index(arr, mid+1, end);

	return index;
}

int main(){
	int arr[] = {-1, 0, 1, 3, 8};
	int size = 5;
	cout<<magic_index(arr,0, 4);
	//cout<<magic_index(arr, 5);	
}