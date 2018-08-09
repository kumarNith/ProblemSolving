#include<iostream>
#include<string>
#include<vector>

using namespace std;

void removeSpace(string &str){
	int length = str.size();
	int count = 0;
	cout<<length<<endl;
	for (int i = 0; i < length; i++){
		if(str[i] != ' '){
			str[count++] = str[i];
		}
	}
	str[count] = '\0'; // Null terminate the string.

}

int main(){
	string str = "You Need To Remove Space";
	removeSpace(str);
	cout<<str<<endl;
}