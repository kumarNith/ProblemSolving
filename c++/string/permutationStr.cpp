#include<iostream>
#include<string>

using namespace std;

int i = 0;

void permutationStr(string str, string append){
	int len = str.size();
	
	
	if(!len){
		i++;
		cout<<append<<endl;
		return;
	}

	for (int i = 0; i < len; i++){
		string str1 = str.substr(0,i)+str.substr(i+1, len);
		permutationStr(str1, append+str.at(i));

	}

}

int main(){
	string str = {"abc"};
	permutationStr(str, " ");
	cout<<i<<endl;
}