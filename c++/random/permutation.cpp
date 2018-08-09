#include<iostream>
#include<vector>
#include<string>

using namespace std;

void allCombanations(string str, string prefix){
	int length = str.size();
	if (!length){
		cout<<prefix<<endl;
	}
	else{
		for (int i = 0; i < length; i++){
			char ch = str[i];
			string s2 = str.substr(0,i) + str.substr(i+1);
			allCombanations(s2, prefix+ch);
		}
	}
}

int main(){
	string str = "abc";
	allCombanations(str, " ");


}