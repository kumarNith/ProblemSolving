#include<iostream>

using namespace std;


int main(){
	unsigned int i = 0;
	unsigned int j = 1;
	int cnt = 4;
	i = ~i;
	cout<<i<<endl;
	i = i<<8;
	while(cnt-- > 1){
		j <<= 1;
		j += 1;
	}
	cout<<"j is "<<j<<endl;
	
	i += j;
	while(i){
		cout<<(i & 1)<<" ";
		i >>=1;
	}
	cout<<endl;
	
	
	cout<<j<<endl;
	cout<<endl;


}