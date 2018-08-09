#include<iostream>
#include<vector>

using namespace std;

int k;
//void sort2arr(){}

int main(){
	int arrB[12] = {1,4,8,10,11,12};
	int arrS[6] = {2,3,5,6,7,9};
	//cout<<sizeof(arr)/sizeof(arr[0])<<endl;
	//for()
	int big   = 5; // cnt-1
	int small = 5; //cnt -1 
	while(big >= 0 || small >= 0){
		k++;
		if (k > 40)
			return -1;
		cout<<"big is "<<big<<", small is "<<small<<endl;
		if (big >=0 && small >=0){
			if(arrB[big]>arrS[small]){
				arrB[big+small+1] = arrB[big];
				big--;
			}
			else{
				//Below I did carless mistake
				// Instead of arrS I put arrB
				arrB[big+small+1] = arrS[small];
				small--;
			}
		}
		else if(small >= 0){

			while(small >= 0){
				cout<<"**********  big is "<<big<<", small is "<<small<<endl;
				arrB[small] = arrS[small];
				small--;
			}
		}
		else if(big >= 0){
			big--;
		}
	}

	for (int i = 0; i < 12; i++){
		cout<<arrB[i]<<" ";
	}
	cout<<endl;
	return 0;
}

