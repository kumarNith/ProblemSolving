#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool strPermCheck(const string &str1, const string &str2 )
{
	int strLen1 = str1.length();
	int strLen2 = str2.length();
	if(strLen1 != strLen2 ){
		return false;
	}
	int char_set[128] = {0};
	for (int i = 0; i < strLen1; i++){
		int asci = str1[i];
		char_set[asci] += 1;
	}
	for ( int i = 0; i <strLen2; i++){
		int asci = str2[i];
		char_set[asci] -= 1;
		if(char_set[asci] < 0)
			return false;
	}
	return true;
}
int main()j
{
	cout<<"Is Kumar &  uKmra str_permute :"<<strPermCheck("Kumar", "uKmra")<<endl; // "Yes":"No" <<endl;
	cout<<"Is abcdef & abdfie str_permute :"<<strPermCheck("abcdef", "abdfie")<<endl;
	//cout<<"Is Nithya uniq :"<<isStringPermutation("Nithya")<<endl;
	//cout<<"Is Palanikumar uniq :"<<isStringPermutation("Palanikumar")<<endl;
	return 0;
}