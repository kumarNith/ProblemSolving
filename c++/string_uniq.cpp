#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isUniqChars(const string &str)
{
	int strLength = str.length();
	if(strLength > 128){
		return false;
	}
	vector<bool> char_set(128);
	for (int i = 0; i < strLength; i++){
		int asci = str[i];
		if(char_set[asci])
			return false;
		else
			char_set[asci] = true;
	}
	return true;
}
int main()
{
	cout<<"Is Kumar uniq :"<<isUniqChars("Kumar")<<endl; // "Yes":"No" <<endl;
	cout<<"Is Nithya uniq :"<<isUniqChars("Nithya")<<endl;
	cout<<"Is Palanikumar uniq :"<<isUniqChars("Palanikumar")<<endl;
	return 0;
}