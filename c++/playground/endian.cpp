#include<iostream>

using namespace std;

int main(){
	unsigned int a = 1;
	char *c = (char*)&a;
	if(*c)
		cout<<"Little endian"<<endl;
	else
		cout<<"Big endian"<<endl;
	getchar();
}