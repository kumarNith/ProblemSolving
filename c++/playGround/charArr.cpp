#include<iostream>

using namespace std;

void modify_charArr(char* ptr){
	ptr[0] = 'H';
	cout<<ptr;
	
}

int main(){
	char arr[20] = "hello,Kumar";
	cout<<arr;
	modify_charArr(arr);
	cout<<"After calling modify : "<<arr
}