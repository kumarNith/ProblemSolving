#include<iostream>
#include<cstring>

using namespace std;
void urlify(char *s1){
	int length;
	length = strlen(s1);
	int spaceCount = 0;
	for(int i =0; i < length;i++){
	    if(s1[i] == ' ')
	        spaceCount++;
	}
	int newLen = length + (spaceCount * 2);
	cout<<"space count"<<spaceCount<<endl;
	s1[newLen--] ='\n';
	for(int i = length -1; i >= 0; i--){
	    if(s1[i] == ' '){
	        s1[newLen--] = '0';
	        s1[newLen--] = '2';
	        s1[newLen--] = '%'  ;
	    }
	    else
	        s1[newLen--] = s1[i];
	}
}

int main(){
	char str[] = "Mr John Smith ";
	cout<<"input string : "<<str<<endl;
	urlify(str);
	cout<<"output string : "<<str<<endl;
	return 0;
}