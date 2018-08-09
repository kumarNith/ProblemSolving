#include<iostream>
#include<string>

using namespace std;

bool isStrstr(string s1, string s2){
	int l1 = s1.size();
	int l2 = s2.size();
	int i = 0;
	for (int j = 0; j < l1; j++){
		while( s1[j]!='\0' && s2[i] != '\0' && s1[j] == s2[i] ){
			j++;
			i++;
		}
		if(i == l2)
			return true;
		else
			i = 0;
	}

	return false;

}

int main(){
	string str = "Hello,World, World";
	string subStr = "World";
	cout<<isStrstr(str,subStr)<<endl;

}