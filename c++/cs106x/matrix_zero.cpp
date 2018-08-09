#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printMatrix(int** arr, int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void setZero(int** matrix, int row, int col){
    cout<<"setZero"<<endl;
	matrix[row][0] = 0;
	matrix[0][col] = 0;
}

void zeroMatrix(int** matrix, int row, int col){
    cout<<"zeroMatrix"<<endl;
	for (int i = 1; i < row; i++){
		if(matrix[i][0] == 0){
			for( int j = 1; j < col; j++)
				matrix[i][j] = 0;
		}
	}

	for (int j = 1; j < col; j++){
		if(matrix[0][j] == 0){
			for( int i = 1; i < row; i++)
				matrix[i][j] = 0;
		}
	}
	
	if(matrix[0][0] == 0){
	    for (int i = 0; i < row; i++)
	        matrix[i][0] = 0;
	    for (int j = 0; j < col; j++)
	        matrix[0][j] = 0;
	}
}

void zeroMatrix_helper(int** matrix, int row, int col){
    cout<<"zeroMatrix_helper"<<endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
		 	if(matrix[i][j] == 0)
		 		setZero(matrix, i , j);
		}  
	}
	zeroMatrix(matrix, row, col);
}


int main(){

	int row = 3;
	int col = 3;
	cout << "Enter number of rows:";
	cin>>row;
	cout << "Enter number of cols:";
	cin>>col;
	//int arr[] = {10,1,10,2,0,1,3,3,20}; int k = 0;
	int** matrix = new int*[row];
	for (int i=0; i < row; i++){
		matrix[i] = new int[col];
	}
    
	std::cout << "Enter row x col matrix \n";
	for ( int i = 0; i < row; ++i ) {
		for ( int j = 0; j < col; ++j ) {
			cin >> matrix[i][j];
			//matrix[i][j] = arr[k++];
		}
	}	
	printMatrix(matrix, row, col);
	zeroMatrix_helper(matrix, row, col);
	printMatrix(matrix, row, col);

}