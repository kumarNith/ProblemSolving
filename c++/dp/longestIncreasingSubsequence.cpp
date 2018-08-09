#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int longestIncSubSeq(vector<int> arr){
	//vector<int> dp;
	int size = arr.size();
	int dpi[size] = {0};
	dpi[size-1] = 1;
	int max;
	for(int i = size-2; i >= 0; i--){
		max = 0; // I set 1 earlier which is worng.
		for(int j = i+1; j < size; j++){
			if(arr[i] < arr[j] && max < dpi[j])
				max = dpi[j];
		}
		dpi[i] = max+1;
	}

	// Just to try in-built fn max_element() 
	max = *(max_element(dpi, dpi+size));

	return max;

}

int main(){
	vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	//{2,7,4,3,8};
	cout<<"Length of longest subsequence is : "<<longestIncSubSeq(arr)<<endl;

}