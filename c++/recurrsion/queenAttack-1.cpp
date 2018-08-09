#include<iostream>
#include<vector>
#include<string>

using namespace std;

int queenAttack(int n, int arr[8][8], int row, int col){
	int right = 0;int left = 0;
	int up = 0;	int down = 0;
	int r_up = 0; int l_down = 0;
	int l_up =0; int r_down = 0;
	int cnt = 0;
	int x = row; int y = col;
	int cnt1=0;int cnt2=0;int cnt3=0;int cnt4=0;



	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j]){
				if( i == row || j == col || i+j == row + col || i - j == row - col)
					cnt++;
			}
		}
	}

	return cnt - 1;
}

int main(){
	int n = 8;
	int arr[8][8];
	/*cout<<"Enter the rows :"<<endl;
	cin>>n;*/
	int x,y;
	for(int i = 0; i < n; i++){
		for(int j=0; j < n; j++){
			arr[i][j] = 1;
		}
	}
	cout<<"Enter Queens pos, x  axis :"<<endl;
	cin>>x;
	cout<<"Enter Queens pos, y  axis :"<<endl;
	cin>>y;
	
	cout<<"Queen can attack "<<queenAttack(n, arr, x, y)<<" positions.";

	
}