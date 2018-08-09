#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count = 0;

bool validPosition(int** board,int board_shape,int row, int col){
	bool valid = true;
	int i,j;
	for(int j = col; j >=0; j--){
	    //cout<<"A "<<;
		if( board[row][j]){
			return false;	
		}
	}	
	// Diagonal -ve slope; backward
	for( i = row,  j = col; i >= 0 && j >= 0; i--,j--){
    	if( board[i][j])
    		return false;
	    }
	
	// Diagonal -ve slope; forward
	for( i = row,  j = col; i <	board_shape && j >=0; i++,j--){
		    if( board[i][j])
			return false;
	}

	return valid;
}

void nQueens_Helper(int col, int board_shape, int**board){
    //cout<<"col is "<<col<<endl;
	if(col >= board_shape){
		//count++;
	    //cout<<"Found col == board_shape"<<endl;
		for(int i = 0; i < board_shape; i++){
			for (int j = 0; j < board_shape; j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		//exit(0);
		cout<<endl;
	}
	else{
	    
		for (int row = 0; row < board_shape; row++){
		    //cout<<"row is "<<row<<" col is "<<col<<endl;
			if(validPosition(board,board_shape,row,col)){
			    //cout<<"Hello"<<endl;
				board[row][col] = 1;
				nQueens_Helper(col+1, board_shape, board);
				//cout<<"aa "<<endl;
			    board[row][col] = 0; // Backtracking 
			}
			
		}
		//nQueens_Helper(col-1, board_shape, &board);
	}
}

int nQueens(int n){
	//int board[n][n];
	// Redo it carefully
	int** board;
	board = new int*[n];
	for(int i = 0; i < n;i++){
	    board[i] = new int[n];
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}
	nQueens_Helper(0,n,board);
}

int main(){
	int n = 3;
	nQueens(n);
	cout<<"Total solutions "<<count<<endl;
}