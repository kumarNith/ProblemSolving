#include<iostream>
#include<vector>
#include<string>

using namespace std;

int k;

void paranthesisUtil(int open, int close, string str){
	k++;
	//cout<<"str is "<<str<<" , "<<open<<" , "<<close<<endl;
	if( !open && !close){// && str.size() == 2*n){
		cout<<endl;
		cout<<"** "<<str<<" **"<<endl;
		cout<<endl;
		return;
	}
	if(open > 0){
		//Using open-- was a terrible mistake
		//cout<<str<<", open "<<open<<", close"<<close<<endl;
		//str+="(";
		//open -=1;
		paranthesisUtil( open-1, close, str+"(");
		//paranthesisUtil(n, --open, close, str+"(");

	}
	//cout<<"1111 , open "<<open<<", close"<<close<<endl;
	if(close > open){
		//cout<<str<<", close "<<close<<", open"<<open<<endl;
		//str+=")";
		//close-=1;
		paranthesisUtil(open, close-1, str+")");
		//paranthesisUtil(n, open,--close,str+")");
	}

	//cout<<"2222 , open "<<open<<", close"<<close<<endl;
}

int main(){
	int n;
	cout<<"Enter the number of  open paranthesis "<<endl;
	cin>>n;
	paranthesisUtil(n ,n, "");

}