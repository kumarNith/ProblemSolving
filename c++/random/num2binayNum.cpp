#include<iostream>
#include<vector>
#include <math.h>

using namespace std;

long long num2BinaryNum(int a){
	long long  sum = 0;
	int i = 0;
	int x = 1;
	while(a){
		sum += ((a & 1) * x);
		x *= 10;
		a >>=1;
	}
	return sum *9;
}

int main(){
	cout<<"enter i :"<<endl;
	int x;
	cin>>x;
	int i = 1;
	long long result;
	while(true){
		result = num2BinaryNum(i++);
		if( result % x == 0)
			break;

	}
	cout<<"Result is : "<<result<<endl;
	
	return 0;
}