#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int findPos(vector<int> arr, int exemption, int length){
	int pos = 0;
	for(int i : arr){
		if(i == exemption)
			break;
		pos++;
	}
	if (pos == length)
		pos = -1;
	return pos;
}

void sortWithExempt(vector<int> &arr, int exemption){
	int length = arr.size();
	int actual_pos = findPos(arr, exemption, length);
	if (actual_pos == -1)
		return;
	sort(arr.begin(), arr.end());
	int curr_pos = findPos(arr, exemption, length);

	if (curr_pos != actual_pos)
	{
		arr[curr_pos] = arr[actual_pos];
		arr[actual_pos] = exemption;

		if(actual_pos > curr_pos){
			sort(arr.begin(), arr.begin()+ actual_pos);
		}
		else{
			sort(arr.begin()+actual_pos+1, arr.end());
		}
	}

}


int main(){
	vector<int> arr = {5,4,6,1,-9,2,9,4, -1, 6};
	//vector<int> arr1 = {-7, 3, 4,-4, -7, -1,9, 4, -4, 0,11};
	vector<int> arr1 = {6,3,-4,9,-12,9};
	sortWithExempt(arr1, -12);
	for (int j : arr1)
		cout<<j<<" ";
	cout<<endl;

}