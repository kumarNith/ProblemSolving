#include<iostream>
#include<string>
#include<vector>

int k;
using namespace std;

bool roboMovement(int arr[][3] , int target){
	int row = 3;
	int col = 3;
	bool found = false;
	int blocked = false;
	for (int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			k++;
			cout<<i<<", "<<j<<" ,value : "<<arr[i][j]<<endl;
			if(arr[i][j] == 0){
				blocked = true;
				break;
			}
			else if (arr[i][j] == target){
				found = true;
				break;
			}
		}
		if(found)
			break;
		//else if (blocked)
		//eds	i--;
	}
	return found;
}


int main(){
	int row = 3;
	int col = 3;
	
	/*cout<<"Enter rows and cols : "<<endl;
	vector<int> route(row,col);// = {0};
	cin>>row;
	cin>>col;*/

	int arr[3][3] = {1};
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			arr[i][j] = 1;
	}
	arr[2][2] = 5;
	arr[1][1] = 0;
	arr[2][1] = 0;
	cout<<roboMovement(arr, 5)<<endl;
	cout<<"Loop count k : "<<k<<endl;
}