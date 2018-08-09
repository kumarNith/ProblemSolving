#include<iostream>
#include<vector>
#include<string>

using namespace std;
static int k;

bool findANumber(vector<vector<int>> arr, int r_s, int c_s, int r_e, int c_e, int row, int col, int target){
	//cout<<endl;
	//cout<<"findANumber():curr_val "<<arr[r_s][c_s]<<", r_s : "<<r_s<<" ,c_s "<<c_s<<" ,r_e "<<r_e<<" , c_e "<<c_e<<endl;
	bool result = false;
	int i;
	if(r_s >= r_e || c_s >= c_e){
		return false;
	}
	if(arr[r_s][c_s] == target){
		//cout<<endl<<"$$ Yeah! We found the value at : r_s "<<r_s<<", c_s "<<c_s<<endl;
		return true;
	}
	for(i = 1; (r_s + i) < r_e && (c_s + i) < c_e ; i++){
		k++;
		//cout<<"Values are [r_s+i][c_s+i]  : "<<arr[r_s+i][c_s+i]<<" ,arr[r_s+i-1][c_s+i-1] "<<arr[r_s+i-1][c_s+i-1]<<endl;
		if(arr[r_s+i][c_s+i] >= target && arr[r_s+i-1][c_s+i-1] <= target){
			//cout<<"Yeah! Making some progress, r_s : "<<r_s<<" , c_s is "<<c_s<<", i is "<<i<<endl;
			cout<<endl;
			if(arr[r_s+i][c_s+i] == target || arr[r_s+i-1][c_s+i-1] == target){
				/*
				if(arr[r_s+i][c_s+i] == target)
					cout<<endl<<"We found the value at : r_s "<<r_s+i<<", c_s "<<c_s+i<<endl;
				else
					cout<<endl<<"We found the value at : r_s "<<r_s+i-1<<", c_s "<<c_s+i-1<<endl;
				*/
				return true;
			}
			
			result = findANumber(arr, r_s , c_s+i , r_s+i , c_e ,  row, col, target);
			if(!result)
				result = findANumber(arr, r_s+i , c_s , r_e, c_e+i , row, col, target);
			//result = findANumber(arr, r_s+i , c_s , row, col, target);
		}
	}
	if(!result && ((r_s + i) < r_e || (c_s + i) < c_e)){
		//cout<<"Ok, I am here, What next ?!"<<endl;
		if((r_s + i) < r_e){
			result = findANumber(arr, r_s + i, c_s, r_e, c_e, row, col, target);
		}
		else if ((c_s + i) < c_e){
			result = findANumber(arr, r_s, c_s + i, r_e, c_e, row, col, target);
		}
	}
	return result;
}

int main(){
	int row, col;
	cout<<"Enter no of rows "<<endl;
	cin>>row;
	cout<<"Enter no of cols "<<endl;
	cin>>col;
	vector<int> row_;
	vector<vector<int>> arr;

	for (int i = 0; i < row; i++){
		for(int j = 1; j <= col; j++){
			//cout<<i*col+j<<" ";
			row_.push_back(i*col+j);
		}
		arr.push_back(row_);
		row_.clear();
	}

	bool result;
	
	
	
	//vector<string> res;
	
	// /*
	for(int cnt = -11; cnt <= (row*col)+10 ;cnt++){
		result = findANumber(arr, 0, 0, row, col, row, col, cnt);
		cout<<"Target ("<<cnt<<") found : "<<(result ? "Yes":"No")<<", and k is "<<k<<endl;
		k = 0;
	}
	// */

	/*
	int target;
	cout<<"Enter the target"<<endl;
	cin>>target;
	result = findANumber(arr, 0, 0, row, col,row, col, target);
	cout<<"Target ("<<target<<") found : "<<(result ? "Yes":"No")<<endl;
	*/
	
	for (int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"K is "<<k<<endl;
	/*
	cout<<"The size of arr "<<arr.size()<<endl;
	cout<<"The size of arr[0] "<<arr[0].size()<<endl;
	cout<<"The size of arr[1] "<<arr[1].size()<<endl;
	cout<<"The size of arr[1] "<<arr[2].size()<<endl; */

}