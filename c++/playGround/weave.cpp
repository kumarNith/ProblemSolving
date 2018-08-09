#include<iostream>
#include<string>
#include<vector>

using namespace std;

void weaveUtil(string str1, string str2, string weav, int size){
	//cout<<"weav : "<<weav<<endl;
	if(!str1.size() && !str2.size()){
		if(weav.size() == size)
		cout<<weav<<endl;
		return;
	}
	for(int i = 0; i < str1.size(); i++){
		weaveUtil(str1.substr(i+1), str2, weav+str1[i], size);		
	}


	for(int j = 0; j < str2.size(); j++){
		weaveUtil(str1, str2.substr(j+1), weav+str2[j], size);	
	}
}

void weave(string str1, string str2){
	weaveUtil(str1, str2, "", str1.size()+ str2.size());
}

int main(){
	string str1 = "1";
	string str2 = "3";
	weave(str1, str2);
	cout<<"*******************"<<endl;
	//weave(str2, str1);
	
}