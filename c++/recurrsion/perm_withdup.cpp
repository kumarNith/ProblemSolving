#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
int k;
using namespace std;

void strPermUtil(map<char, int> myMap,string str, string perm, int size ){
	//cout<<perm<<", k is "<<k<<endl;
	k++;
	if(size == perm.size()){
		cout<<perm<<endl;
		return;
	}
	int dSize = str.size();
	for(int i = 0; i < dSize; i++){
		if(!myMap[str[i]]){
			continue;
			//cout<<"$$$ dStr is "<<str<<endl;
		}
		myMap[str[i]] -= 1;
		strPermUtil(myMap, str, perm+str[i],size);
		myMap[str[i]] += 1;

		
	}
}

int main(){
	string str;
	cout<<"Enter the string "<<endl;
	cin>>str;
	int size = str.size();
	string distinctStr;// = sort(str.begin(), str.end());
	map<char, int> myMap;
	for (int i = 0; i < size; i++){
		if(myMap.find(str[i]) == myMap.end()){
			myMap[str[i]] = 1;
			distinctStr.push_back(str[i]);
		}
		else{
			myMap[str[i]] += 1;
		}
	}
	cout<<"Calling strPermUtil with : "<<distinctStr<<endl;
	strPermUtil(myMap, distinctStr, "",  size);
	cout<<endl;
	cout<<"---------------"<<endl;
	cout<<k<<endl;
	
}