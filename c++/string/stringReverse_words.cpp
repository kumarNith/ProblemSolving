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
	char* end = NULL;
	int i = 0;
	while(*curr++){
		//cout<<curr[0]<<" "<<i++<<endl;
		if(*curr == ' '){
			end = curr;
			reverse(start,end);
			start = curr+1;
		}
		
		if(*curr == '\0'){
			//cout<<"Single str is "<<str<<endl;
			//cout<<" Hey, its NULL"<<endl;
			end = curr;
			reverse(str,end-1);
		}
	}
}

int main(){
	char *str = new char[30];
	//strcpy(str,"Hello, how ");
	//char str[25];
	strcpy(str,"Hello, how are you? ");
	cout<<"Actual str is : "<<str<<endl;
	reverseStrbyWords(str);
	//reverseWithDelimiter(str, NULL);
	cout<<"Reversed str is : "<<str<<endl;

	
}
