// Example program
#include <iostream>
#include <string>
#include <set>

using namespace std;
/*
void permutation1(string str, string ss){
    int len = str.length();
    if(str.size() == 0){
        cout<<ss<<endl;
    }
    for(int i = 0; i < len; i++)
    {
        char ch = str[i];
        permutation(str.substr(0,i)+str.substr(i+1), ss+ch);
    }
}*/

void permutation(string str, set<string>& mySet){
    int len = str.length();
    if(str.size() == 0){
        return;
    }
    //cout<<str<<endl;
    mySet.insert(str);
    for(int i = 0; i < len; i++)
    {
       // char ch = str[i];
        permutation(str.substr(0,i)+str.substr(i+1), mySet);
    }
}


int main()
{
    string str;
    set<string> mySet;
    cout<<"Enter a str"<<endl;
    cin>>str;
    permutation(str, mySet);
    set<string>::iterator it;
    for(it = mySet.begin(); it !=mySet.end(); it++)
        cout<<*it<<endl;
    return 0;
    
  
}
