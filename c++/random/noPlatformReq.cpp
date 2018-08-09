#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int noPlatformRequired(vector<int> arr, vector<int> dep){
	int platforms = 0;
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int arr_top;
	int dep_top;
	int size;
	while(arr.size() && dep.size()){
		arr_top = arr.front();
		dep_top = dep.front();
		cout<<arr_top<<" "<<dep_top<<endl;
		//if(arr_top > dep_top){
		if(dep_top >= arr_top){
			platforms++;
			//size = arr.size() -1;
			arr.erase(arr.begin());
		}
		else{
			platforms--;
			//size = dep.size() -1;
			dep.erase(dep.begin());
		}
	}
	return platforms;
}

int main(){
	/*Assumes that all train arrives on a day departure 
	the same day*/
	vector<int> arrival   = {1000, 1030, 700,  900, 915,  915, 1100, 1015};
	vector<int> departure = {1200, 1045, 1500, 945, 1000, 930, 1105, 1145};
	cout<<"No of platforms required : "<<noPlatformRequired(arrival, departure)<<endl;
}
