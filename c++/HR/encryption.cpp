#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;
string encryption(string str){
	int size = str.size();
	int row = sqrt(size);
	int col;
	string encrypted = "";
	
	if(row*row == size){
		col = row;
	}
	else{
		col = row+1;
		//Before adding this, my code failed for the string "Chillout"
		if(row*col < size){
			row++;
		}
	}
	

	for(int j = 0; j < col; j++){
		for (int i = 0; i < row; i++){
			if(size > j+(i*col))
				encrypted += str[j+(i*col)];
		}
		cout<<encrypted<<endl;
		encrypted += " ";
	}
	return encrypted;
}


int main(){
	string str;
	cout<<"Enter the string "<<endl;
	cin>>str;
	string encrypted = encryption(str);
	cout<<"Encrypted string is "<<endl;
	cout<<encrypted<<endl;
}