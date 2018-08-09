#include<iostream>
#include<string>
#include<vector>

using namespace std;

int cnt; //Just to cnt it.

void exploreAllPossiblitiesUtil(int n, int curr, int step_size, string str){
	if(n == curr){
		cout<<str<<endl;
		cnt++;
		return;
	}
	if(curr >n){
		return;
	}
	for(int i = 1; i <= step_size; i++){
		exploreAllPossiblitiesUtil(n, curr+i, step_size, str + to_string(i));
	}
}
void exploreAllPossiblities(int n, int step_size){
	exploreAllPossiblitiesUtil(n, 0, step_size, "");
}

int main(){
	int n;
	int step_size;
	cout<<"Enter the total steps"<<endl;
	cin>>n;
	cout<<"Step sizes : "<<endl;
	cin>>step_size;
	exploreAllPossiblities(n,step_size);
	cout<<"cnt is : "<<cnt<<endl;
	
}