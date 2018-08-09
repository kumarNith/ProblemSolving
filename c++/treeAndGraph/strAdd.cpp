#include<iostream>
#include<string>

using namespace std;

string string_addition(string str1, string str2){
	int len1 = str1.size();
	int len2 = str2.size();
	string bigger;
	string smaller;
	int max;
	int min;
	int carry = 0;
	int val1, val2;
	int sum;
	if(len1 > len2){
		bigger = str1;
		smaller = str2;
		max = len1-1;
		min = len2-1;
	}
	else{
		bigger = str2;
		smaller = str1;
		max = len2-1;
		min = len1-1;
	}

	string result;
	while (max>=0 && min >=0){
		val1 = bigger[max--] - '0';
		val2 = smaller[min--] - '0';
		//cout<<str1[i] - '0'<<" , "<<str2[i] - '0'<<endl;
		sum = val1 + val2 + carry;
		carry = sum/10;
		sum %= 10;  
		result.insert(0, to_string(sum));

	}
	
	while(max >= 0){
		sum = bigger[max--] - '0' + carry;
		carry = sum/10;
		sum %= 10;  
		result.insert(0, to_string(sum));
	}
	
	/*
	while(str1.size() && str2.size()){

	}*/
	if(carry)
		result.insert(0, to_string(carry));
	return result;
}

int main(){
	string str1;// = "182";
	string str2;// = "345";
	cout<<"Enter num1"<<endl;
	cin>>str1;
	cout<<"Enter num2"<<endl;
	cin>>str2;
	cout<<string_addition(str1,str2);
	return 0;
}
