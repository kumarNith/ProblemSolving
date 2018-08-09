#include<iostream>
#include<string>
#include<vector>

using namespace std;

string stringCompression(string s1){
	int length = s1.length();
	char prev_ch = s1[0];
	int count = 1;
	char ch;
	string str_cmp;

	if(length > 1){
		for(int i=1; i < length; i++){
			if(s1[i] == prev_ch)
				count++;
			else{
				str_cmp.push_back(prev_ch);
				ch = '0' + count;;
				str_cmp.push_back(ch);
				count = 1;
				prev_ch = s1[i];
			}
		}
	}
	str_cmp.push_back(prev_ch);
	ch = '0' + count;
	str_cmp.push_back(ch);
	return str_cmp;
}

int main(){
    string s1 = "abbcccdddde";
    string str_cmp = stringCompression(s1);
    cout<<str_cmp<<endl;
    string s2 = "a";
    str_cmp = stringCompression(s2);
    cout<<str_cmp<<endl;
	return 0;
}