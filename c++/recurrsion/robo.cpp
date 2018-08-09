#include<iostream>
#include<string>
#include<vector>

int k;
int n = 7;
using namespace std;

int arr[7][7];
bool roboMovement(int row, int col, int target){
	
	bool found = false;
	k++;
	//cout<<"row : "<<row<<", col "<<col<<endl;

	if(row >= n ||  col >= n ){
		cout<<"Not a valid path :  row : "<<row<<", col "<<col<<endl;
		return false;
	}
	if(arr[row][col] <= 0){
		cout<<"Blocked at  row : "<<row<<", col "<<col<<endl;
		//cout<<"Found val @ row : "<<row<<" , col : "<<col<<endl;
		return false;
	}
	
	if(arr[row][col] == target){
		//cout<<"Found val @ row : "<<row<<" , col : "<<col<<endl;
		return true;
	}
	
	arr[row][col] = -1;

	if(!found){
		cout<<"Going to call row : "<<row<<", col "<<col+1<<endl;
		found = roboMovement(row, col+1, target);
	}
	if(!found){
		cout<<"** row : "<<row+1<<", col "<<col<<endl;
		found = roboMovement(row+1, col, target);
	}
	return found;
}


int main(){
	int row = 7;
	int col = 7;
	//int n = 7;
	
	/*cout<<"Enter rows and cols : "<<endl;
	vector<int> route(row,col);// = {0};
	cin>>row;
	cin>>col;*/

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			arr[i][j] = 1;
	}
	arr[6][6] = 5;
	
	arr[0][6] = 0;arr[1][5] = 0;arr[2][4] = 0;
	arr[2][1] = 0;//arr[1][2] = 0;
	arr[3][4] = 0;arr[4][3] = 0;arr[5][2] = 0;
	arr[5][1] = 0;//arr[2][3] = 0;
	arr[4][5] = 0;arr[5][5] = 0;
	
	/*
	arr[5][6] = 0;
	arr[6][5] = 0;
	*/

	//arr[2][1] = 0;
	//arr[1][2] = 0;
	cout<<roboMovement(0,0, 5)<<endl;
	cout<<"Loop count k : "<<k<<endl;
}