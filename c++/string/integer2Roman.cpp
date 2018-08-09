#include<vector>
#include<iostream>
#include<string>
#include<map>
using namespace std;

vector<int> rVal = {50,10,5,1};
map<int, char> roman = {{1, 'I'},{5, 'V'},{10, 'X'},{50,'C'},{100,'L'}}; 
void int2Roman(int n, string romanEq){
	int len = rVal.size();
	for(int i = 0; i <len;i++){
		int val = rVal[i];
		if((n/val) > 0){
			
		}
	}
}



int main(){
	int n;
	cout>>"Enter the number "<<endl;
	cin>>n;
	int2Roman(n,"");



}

/*
void int2Roman(int n, string romanEq){
	if(n > 39 || n < 1) // Max suppoerted number
		return;

	if(n ==0)
		cout<<romanEq;
	int j = 0;

	for (int i : rVal){
		if(n / i >= 3){
			romanEq.append("XXX");
			int2Roman(n%(3*i), romanEq);
		}
		
		if((n/i) > 0 && (n/i) < 3){
			romanEq.append("X");
			int2Roman(n-i, romanEq);
		}
		else{
			int temp = n / (rVal[j+1])
			if(temp > 3)
		}
		j++;

	}
}
*/