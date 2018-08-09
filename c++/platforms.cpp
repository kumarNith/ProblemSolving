#include<iostream>
#include<string>
#include<vector>


int findMinPlatforms(vector<int> arr, vector<int> dep){
	int reqPlatforms = 0;
	int size = arr.size();
	if(!size || arr.size() != dep.size()){
		return reqPlatforms;
	}
	reqPlatforms++;
	for(int i = 1; i < size; i++){
		arr
	}
}

int main(){

	vector<int> arr = {900, 925, 1000};
	vector<int> dep = {930,950,1100};
	cout<<findMinPlatforms();
	return 0;
	
}
