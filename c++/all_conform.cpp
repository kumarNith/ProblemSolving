#include<iostream>
#include<vector>

using namespace std;


int main(){
	vector<int> arr = {1,0,0,1,0,1,1,0,0,0,1};
	int len 		= arr.length();
	int cnt = 1;
	for (int j = 1; j < len; j++){
		if(arr[j] != arr[j-1])
			cnt++
	}

	cout<<cnt<<endl;
}