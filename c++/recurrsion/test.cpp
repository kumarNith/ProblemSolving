// Example program
#include <iostream>
#include <string>
#include<stack>

using namespace std;

int main()
{
  stack<int> s1;
  //cout<<s1.size()<<endl;
  cout<<s1.top()<<endl;
  cout<<"hello"<<endl;
  s1.pop();
  cout<<s1.size()<<endl;
  return 0;
}
