#include<iostream>
#include<vector>

using namespace std;


vector<int> merge(vector<int> left, vector<int> right){
	int l_len = left.size();
	int r_len = right.size();
	int i = 0;
	vector<int> merged = {};
	static int i1 = 0;
	cout<<"i1 is "<<i1++<<", "<<l_len<<" "<<l_len<<endl;
	while(l_len && r_len){
		if(left[i] >= right[i]){
			merged.push_back(right[i]);
			//right.pop_back(i);
			right.erase(right.begin());
			r_len--;
		}
		else{
			merged.push_back(left[i]);
			left.erase(left.begin());
			l_len--;
		}
	}

	while(r_len){
			merged.push_back(right[i]);
			right.erase(right.begin());
			r_len--;
	}

	while(l_len){
		merged.push_back(left[i]);
		left.erase(left.begin());
		l_len--;
	}
	return merged;
}

vector<int> mergeSort(vector<int> arr){
	int len = arr.size();
	if(len <= 1)
		return arr;
	vector<int> left;
	vector<int> right;
	int mid = len/2;

	for(int i = 0; i < mid; i++){
		left.push_back(arr[i]);
	}

	for(int j = mid; j < len; j++){
		right.push_back(arr[j]);
	}

	return merge(mergeSort(left),mergeSort(right));
}


int main(){
	vector<int> arr = {1,-2,1,0,5,4,6,9,3,-1,12};
	vector<int> sorted;
	for (int j : arr){
		cout<<j<<" ";
	}
	cout<<endl;
	sorted = mergeSort(arr);
	cout<<"After mergeSort : "<<endl;
	for (int j : sorted){
		cout<<j<<" ";
	}
	cout<<endl;


}