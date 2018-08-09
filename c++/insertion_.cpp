#include<iostream>
using namespace std;
int* insertion_sort(int a[],int len){
	for(int i = 1; i<len ; i++){
		int j = i-1;
		int key = a[i];
		while (j >= 0 and a[j] > key){
			a[j+1] = a[j];
			a[j] = key;
			j--;
		}
	}
	return a;
}
int main(){
	int arr[] = {6,3,8,9,-1,5,12,2};
	int *sorted_arr;
	int len = sizeof(arr)/sizeof(int);
	cout<<"Un sorted list";
	for(int a = 0; a < len;a++)
	    cout<<" "<<arr[a];
	cout<<endl;
	sorted_arr = insertion_sort(arr, len);
	cout<<"Sorted list";
	for(int a = 0; a < len;a++)
	    cout<<" "<<sorted_arr[a];
	cout<<endl;
	return 0;
}