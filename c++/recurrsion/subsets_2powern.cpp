#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

vector<string> getSubStringUtil(string str){
	int size = str.size();
	int val = 1;
	vector<string> subsets;
	string ss;
	int index = 0;
	// I failed to add the below logic at first.
	int couter = pow(2,size);
	for (int i = 0; i <= couter; i++){
		//index = 0;
		for (int k = i, index = 0; k > 0; k = k>>1, index++){
			if(k & 1){
				ss += str[index];
				//cout<<str[index]<<" ";
			}
		}
		//cout<<endl;
		//cout<<"ss is "<<ss<<endl;
		subsets.push_back(ss);
		ss.clear();
	}
	return subsets;
}

int main(){
	string str;
	cout<<"Enter the set :"<<endl;
	cin>>str;
	vector<string> subsets = getSubStringUtil(str);
	for (string s : subsets){
		cout<<s<<endl;
	}
	return 0;
}