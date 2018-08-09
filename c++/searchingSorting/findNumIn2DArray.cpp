// Find a number in a 2D sorted array.
//Elements are sorted in ascending order in both row and col wise.
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool findANumberUtil(vector<vector<int>> arr, int row,int start, int end, int target){
	//cout<<"findInRotatedSortUtil() "<<start<<" end "<<end<<endl;
	bool  found = false;
	if(end < start)
		return found;
	int mid = (start + end)/2;
	if(arr[row][mid] == target){
		cout<<"Found "<<mid<<endl;
		return true;
	}
	else if(arr[row][mid] > target)
		found = findANumberUtil(arr, row, start, mid-1, target);
	else
		found = findANumberUtil(arr, row, mid+1, end, target);

	return found;
}

bool findANumber(vector<vector<int>> arr, int row, int col, int target){
	bool result = false;
	for (int i = 0; i < row; i++){
		result = findANumberUtil(arr, i, 0, col-1, target);
		if(result){
			break;
		}
	}
	return result;
}
int main(){
	vector<vector<int>> arr = {{3,4,15},{11,12,17},{20,21,22}};
	int row = 3;
	int col = 3;
	int target;
	cout<<"Enter the number to find"<<endl;
	cin>>target;
	cout<<"Does the "<<target<<", is in arr : "<<(findANumber(arr,row, col, target) ? "Yes":"No")<<endl;
	return 0;
}