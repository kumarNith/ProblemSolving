#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	int arr[] = {3,1,2,6,7,4,22,11,5};
	cout<<"Enter the sum "<<endl;
	int target=0;
	cin>>target;
	int sum = 0;
	int length = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+length);
	
	/*
	cout<<"Sorted array"<<endl;
	//To display the integer array
	for (int k = 0; k < length; k++)
		cout<<arr[k]<<" ";
	cout<<endl;*/

	for (int i = 0; i < length-2; i++){
		int r = i+1;
		int l = length-1;
		while (r < l){
			//cout<<i<<r<<l<<endl;
			sum = arr[i] + arr[r]+arr[l];
			if(sum == target){
				cout<<"Found the target"<<endl;
				cout<<"Triplet position is "<<i<<" "<<r<<" "<<l<<endl;
				return 0;
			}
			if (sum > target)
				l--;
			else
				r++;
		}
	}
	cout<<"Couldn't find the target"<<endl;
	return 0;
}