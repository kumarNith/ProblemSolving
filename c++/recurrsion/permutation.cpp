#include<iostream>
#include<vector>
#include<string>
#include<set>

int k;

using namespace std;
void subSets(string str, string ss, set<string> &mySet){
	int size = str.size();
	k++;
	mySet.insert(str);
	/*if(size == 0){
		//cout<<ss<<endl;
		
		mySet.insert(ss);
		//return; 
	}*/

	for(int i = 0; i < size; i++){
		char ch = str[i];
		//if(i == 0)
		//	subSets(str.substr(0,i) + str.substr(i+1), ss+ch, mySet);
		/*else
			subSets(str.substr(0,i) + str.substr(i+1), "", mySet);
			*/
		subSets(str.substr(0,i) + str.substr(i+1), "", mySet);
	}

}

int main(){
	string str;
	set<string> mySet;
	cout<<"Enter the string : "<<endl;
	cin>>str;
	cout<<endl;
	subSets(str,"", mySet);
	set<string>::iterator it;
	for (it = mySet.begin(); it != mySet.end(); it++)
		cout<<*it<<endl;
	cout<<" k is "<<k<<endl;
}
