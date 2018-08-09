#include<iostream>

using namespace std;

int main(){
	//unsigned int x = 151;
	//unsigned int y = 0;

	int x = 151;
	int y = 0;
	
	/*
	int size = sizeof(int);
	cout<<"Sizeof int : "<<size<<endl;
	for(int i = 0; i < size * 8; i++){
		cout<<((x>>1)& 1 )<<" ";
		//x = x >>1;
	}
	cout<<endl;*/
	//cout<<(x<<2)<<endl;
	int a = 32;
	while(a){
		cout<<(x & 1)<<" ";
		y += (x & 1);
		if(a > 1)
			y = y << 1;
		x = x>>1;
		a--;
		//cout<<", "<<x<<endl;
	}
	cout<<endl;
	a = 32;
	while(a){
		//cout<<(x & 1)<<" ";
		cout<<(y & 1)<<" ";
		y >>= 1;
		a--;

	}
	/*
	while(y){
		cout<<(y & 1)<<" ";
		y >>= 1;
	}*/
	return 0;
}