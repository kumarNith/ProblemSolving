#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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

string strMultiplication(string str1, string str2){
	//string res_tmp;
	int len1 = str1.size();
	int len2 = str2.size();
	string result;
	string res_temp;
	int mul = 0;
	int carry = 0;
	int val, i,j,k;
	int si,sj;
	//cout<<"strMultiplication() "<<len1<<" "<<len2<<endl;
	
	for ( i = len1-1;  i >= 0 ; i--){
		 si = str1[i] - '0';
		for( j = len2-1; j >= 0; j--){
		    sj = str2[j] - '0';
		    //cout<<si<<" , "<<sj<<endl;
			mul = si * sj + carry;
			val = mul % 10;
			res_temp.insert(0, to_string(val));
			carry = mul / 10;
		}
		if(carry){
			res_temp.insert(0, to_string(carry));
			carry = 0;
		}
		for(k = (len1-1) - i; k > 0; k--)
			res_temp.push_back('0');
		result = string_addition(res_temp, result);
		res_temp.erase();
	}

	//string_addition(result)
	return result;
}

int main(){
	/*string str1,str2;
	string result;
	cout<<"Enter num1"<<endl;
	cin>>str1;
	cout<<"Enter num2"<<endl;
	cin>>str2;
	result = strMultiplication(str1, str2); */
	string result;
	int n;
	cout<<"Enter the n "<<endl;
	cin>>n;
	result = to_string(n);
	for(int i = n-1; i > 0;i--)
		result = strMultiplication(result, to_string(i));
	cout<<"Result is "<<result;
	return 0;
}