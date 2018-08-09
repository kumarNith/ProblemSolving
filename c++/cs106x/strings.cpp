#include<iostream>
#include<string>

using namespace std;
void stringOps(string s1){
	string s2 = "kumar";
	s1.append(s2);
	cout<<s1<<endl;
	cout<<"Same : "<<s1.compare("Palanikumar")<<endl;
	cout<<"Diff : "<<s1.compare("Palani kumar")<<endl;
	cout<<"str length : "<<s1.length()<<endl;
	cout<<"find :"<<s1.find("pal")<<endl;
	//cout<<"can't find :"<<s1.find("nith")<<endl;
	
	string s = "Hi";
	s += 41;
	cout<<"string + int : "+s<<endl;
	string s42 = "42";
	cout<<"str to int : "<<(int) s42;
	
}

int main(){
	string s1 = "Palani";
	stringOps(s1);
	cout<<s1;
	return 0;
}