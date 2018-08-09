#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string smaller(string str){
	string small;
	return small;
}

string bigger(string str){
	string big = "no answer";
	int size = str.size() - 1;
	bool found = false;
	int start;
	int end;
	//What if it is case-sensitive
	
	for (int i = size; i >0; i--){
		//int curr_max = str[i] - 'a';
		//for(int j = i-1; j >= 0; j--){
			//cout<<str[i]<<" ,current max "<<endl;
			if(str[i] > str[i-1]){
				//-----//
				cout<<str[i]<<" ,current max "<<endl;
				int j;
				for( j = size; j > i; j--)
				{
					if(str[j] > str[i-1]){
						break;
					}
				}
				//------------//
				cout<<"Found"<<endl;
			//	cout<<str[i]<<" ,current max is : "<<curr_max<<endl;
				
				char ch = str[i-1];
				str[i-1] = str[j];
				str[j] = ch;
				cout<<"Before : "<<str<<endl;
				//sort(str.begin()+j+1, str.end());
				for( end = size,  start = i; end > start; start++, end--){
					cout<<"I am here"<<endl;
					char temp = str[end];
					str[end] = str[start];
					str[start] = temp;
				}
				return str;
			}
		}
	return big;
}



int main(){
	string str;
	cout<<"Enter the string "<<endl;
	cin>>str;
	string s1 = bigger(str);
	cout<<"Result is : "<<s1<<endl;
	return 0;
}
