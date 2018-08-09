#include<iostream>
#include<string.h>

using namespace std;

void reverse(char* start, char* end){
	//cout<<str<<endl;
	//cout<<"Hi"<<endl;
	char* temp = start;
	//cout<<temp<<endl;
	while(end > start){
		char ch = *end;
		*end-- = *start;
		*start++ = ch;
	}
	//cout<<temp<<endl;
}

void reverseStrbyWords(char* str){
	if(str == NULL)
		return;
	
	//int len = strlen(str);
	char* start = str;
	char* curr = str;

	while(*curr){
		curr++;
		if(*curr == ' '){
			reverse(start,curr-1);
			start = curr+1;
		}
		
		if(*curr == '\0'){
			//cout<<"Single str is "<<str<<endl;
			//cout<<" Hey, its NULL"<<endl;
			reverse(start,curr-1);
		}
		//curr++;
	}

	//Now, do the "double reverse"
	reverse(str,curr-1);
}

int main(){
	char *str = new char[30];

	strcpy(str,"Hello, how are you? ");
	cout<<"Actual str is : "<<str<<endl;
	reverseStrbyWords(str);
	cout<<"Reversed str is : "<<str<<endl;
	
}
