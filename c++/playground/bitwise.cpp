#include<iostream>

using namespace std;

int main(){
	int a = 23;
	int b = 35;
	cout<<"(a & b) : "<<(a & b)<<endl;
	cout<<"(a | b) : "<<(a | b)<<endl;
	int c = 13;
	int d = 60;
	cout<<" c | d "<< (c | d)<<endl<<"c+d : "<<c+d<<endl;
	cout<<" c ^ d : "<<(c ^ d)<<endl;
	cout<<" c << 2 : "<<(c << 2)<<endl;
	cout<<" c >> 2 : "<<(c >> 2)<<endl;
	int x = 1;
	int cnt = 0;
	c = 63;
	cout<<"No of bits set in c : "<<c;
	while(c){
		if(c & 1)
			cnt++;
		c = c >> 1;

	}
	cout<<" is  "<<cnt <<endl;
}