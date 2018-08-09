#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include <cmath>


bool isOneEditAway(string s1, string s2){
	int len_s1 = s1.length();
	int len_s2 = s2.length();
	if(abs(len_s1 - len_s2))
		return false;
	string smaller = len_s1 < len_s2 ?  s1 : s2;
	string bigger  = len_s1 > len_s2 ?  s1 : s2;

	len_s1 =  smaller.length();
	len_s2 =  bigger.length();
	int i , j = 0;
	bool oneDiff = false;
	while( i < len_s1 && j < len_s2){
		if(bigger[i] != smaller[j]){
			if (oneDiff)
				return false;
			oneDiff = true;
			if(len_s1 == len_s2){
				i++;
				j++;
			}
			else{
				j++;
			}
		}
	}
}


int main(){
	string s1 = "abcdef";
	string s2 = "abcdgf";
	cout<<"oneEditAway -  "<<isOneEditAway(s1,s2)<<endl;

}