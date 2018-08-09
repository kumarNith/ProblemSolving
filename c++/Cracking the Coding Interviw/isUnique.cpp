#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;
/*
Using bool vector
ASCII encodes 128 specified characters into seven-bit integers
*/
bool isUniqueCharsInStr(string str){
	vector<bool> charLst(128);
	int asc;
	int len = str.length();
	if (len > 128)
		return false;
	for(int i = 0; i < len; i++){
		asc = str[i];
		if (charLst[asc])
			return false;
		else
			charLst[asc] = true;
	}

	return true;
}

/*
Using inbuilt algorithm
*/
bool isUniqueChars(string str){
	int len = str.length();
	if (len > 128)
		return false;
	sort(str.begin(), str.end());
	for(int i =0; i < len-1; i++){
		if(str[i] == str[i+1])
			return false;
	}
	return true;

}

/*
using bitset()
*/
bool isUniqueChars_bitset(string str){
	int len = str.length();
	if (len > 128)
		return false;
	bitset<128> charLst(0);
	int asc;
	for(int i =0; i < len; i++){
		asc = str[i];
		if(charLst.test(asc))
			return false;
		else
			charLst.set(asc,1);
	}
	return true;

} 

int main(){
	string str = "abcdefgh";
	cout<<"is string - "<<str<<" - unique : "<<(isUniqueCharsInStr(str) ? "true" : "false")<<endl;
	cout<<"is string - "<<str<<" - unique : "<<(isUniqueChars(str) ? "true" : "false")<<endl;
	cout<<"is string - "<<str<<" - unique : "<<(isUniqueChars_bitset(str) ? "true" : "false");
	return 0;
}