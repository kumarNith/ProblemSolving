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

	/*
		-ve slope down
	*/
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){ // 
		if(arr[x][y]){
			cout<<"x is : "<<x<<" , y is "<<y<<endl;
			++cnt;
			++cnt1;
			cout<<"-------"<<endl;
		}
		else{
			cout<<"BREAKING : x is : "<<x<<" , y is "<<y<<endl;
			break;
		}
		x++;
		y++;
	}
	cout<<"1 cnt is "<<cnt<<endl;
	/*
		-ve slope up
	*/
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cout<<"x is : "<<x<<" , y is "<<y<<endl;
			++cnt;
			++cnt2;
			cout<<"++++++"<<endl;
		}
		else
			break;
		x--;
		y--;
	}
	cout<<"2 cnt is "<<cnt<<endl;
	/*
		+ve slope down
	*/
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		x++;y--;
	}
	cout<<"3 cnt is "<<cnt<<endl;
	/*
		+ve slope up
	*/
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		x--;y++;
	}

	cout<<"4 cnt is "<<cnt<<endl;
	//----------------------------
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		x++;
	}
	cout<<"5 cnt is "<<cnt<<endl;
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		x--;
	}
	cout<<"6 cnt is "<<cnt<<endl;

	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		y++;
	}
	cout<<"7 cnt is "<<cnt<<endl;
	x = row;
	y = col;
	while((x >= 0 && x < 8) && ((y >= 0 && y < 8))){
		if(arr[x][y]){
			cnt++;
		}
		else
			break;
		y--;
	}
	cout<<"8 cnt is "<<cnt<<endl;

	return cnt-8;
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