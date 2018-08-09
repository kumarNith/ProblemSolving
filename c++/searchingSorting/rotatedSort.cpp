#include<iostream>
#include<vector>

using namespace std;

int findInRotatedSortUtil(int arr[], int start, int end, int target){
	cout<<"findInRotatedSortUtil() "<<start<<" end "<<end<<endl;
	int pos = -1;
	if(end < start)
		return -1;
	int mid = (start + end)/2;
	if(arr[mid] == target){
		cout<<"Found "<<mid<<endl;
		return mid;
	}
	else if(arr[mid] > target)
		pos = findInRotatedSortUtil(arr, start, mid-1, target);
	else
		pos = findInRotatedSortUtil(arr, mid+1, end, target);

	return pos;
}

int findInRotatedSort(int arr[], int start, int end, int target){
	int pos = -1;
	cout<<"findInRotatedSort(), start "<<start<<", end "<<end<<endl;
	if(end < start)
		return -1;
	//Todo : Can make the logic better . Do I really need the below. arr = {7,7,7,7} find 6 ?
	//Why I didn't find the below earlier. Actually it's a bug.
	
	/*if (end == start){
		cout<<"start is EQUAL to end : start is "<<start<<endl;
		if(arr[end] != target){
			return -1;
		}
		else
			return end;
	}*/

	if (end - start == 1){
		if (arr[start] == target)
			return start;
		else if (arr[end] == target)
			return end;
	}
	int mid = (start + end)/2;

	// I coded arr[start] <= arr[mid-1] and it got failed.
	// I could have check that before I compiled it.
	if(arr[start] < arr[mid]){
		cout<<"**** start "<<start<<", end : "<<end<<endl;
		pos = findInRotatedSortUtil(arr, start, mid, target);
		if(pos == -1){
			cout<<"**** mid "<<mid<<", end : "<<end<<endl;
			pos = findInRotatedSort(arr, mid,end, target);
		}

	}
	else {//if(arr[mid] <= arr[end]){
		cout<<"$$$$ -- start "<<start<<", end : "<<end<<endl;

		//pos = findInRotatedSort(arr, mid, end, target);
		pos = findInRotatedSortUtil(arr, mid, end, target);
		if(pos == -1){
			cout<<"$$$$$ mid "<<mid<<", start "<<start<<", end : "<<end<<endl;
			pos = findInRotatedSort(arr, start, mid-1, target);
		}
	}
	return pos;

}

int main(){
	//int arr[] = {7,8,9,1,2,3,4,5,6};
	//int arr[] = {7,7,7,7};
	int arr[] = {5,99	};
	int target;
	cout<<"Enter the target"<<endl;
	cin>>target;
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Index of the target : ";
	cout<<"Target is : "<<findInRotatedSort(arr, 0, size-1, target);
	
}