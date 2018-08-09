#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool checkPermutation(string s1, string s2){
	int length_s1 = s1.length();
	int length_s2 = s2.length();
    int char_count[128]	 = {0};
    int asci;
  
	if (length_s1 != length_s2)
		return false;
	for (int i = 0; i < length_s1; i++){
		asci = s1[i];
		char_count[asci]++;
	}
	for (int i = 0; i < length_s2; i++){
		asci = s2[i];
		char_count[asci]--;
		if(char_count[asci] < 0){

			return false;
		}
	}
	return true;
}

int main(){
	string s1 = "1@abc!! xyz";
	string s2 = "!1zyx cba!@";
	cout<<" checkPermutation - "<<(checkPermutation(s1,s2) ? "true" : "false")<<endl;

}