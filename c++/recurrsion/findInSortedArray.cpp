#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main(){
	int row, col;
	cout<<"Enter no of rows "<<endl;
	cin>>row;
	cout<<"Enter no of cols "<<endl;
	cin>>col;
	vector<vector<int>> arr;

	for (int i = 0; i <= row; i++){
		for(int j = 0; j <= col; j++){
			arr[i].push_back(i*j+j+1);
		}
	}

	for (int i = 0; i <= row; i++){
		for(int j = 0; j <= col; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}