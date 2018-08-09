#include<iostream>
#include <string.h>
using namespace std;

int str_count(char *str){
	if(str == NULL)
		return 0;
	int count = 0;
	while(*str++)
		count++;
	return count;
}




int main(){
	char *str = new char[15];

	strcpy(str,"Hello,World!");
	cout<<str<<endl;
	int len = str_count(str);
	char *start = str;
	char *end = start + len - 1;
	while(end > start){
		char ch = *start;
		*start++ = *end;
		*end-- = ch;
	}
	cout<<"Reversed string is : "<<str<<endl;
}