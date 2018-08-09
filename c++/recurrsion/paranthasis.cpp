// Example program
#include <iostream>
#include <string>

using namespace std;

void paranthesis(string open, string close, string str){
    if(!(open.size() + close.size())){
        cout<<str<<endl;
       // str = "";
        return;
       // exit();
    }
    if(open.size()){
        //cout<<"***** "<<str<<endl;
        paranthesis(open.substr(1),close, str+open[0]);
        
    }
    if(close.size() && (open.size() != close.size())){
        //cout<<"####### "<<open<<endl;
        //cout<<"$$$$$$$ "<<close<<endl;
        //cout<<"####### ==> "<<str+close[0]<<endl;
        paranthesis(open,close.substr(1), str+close[0]);
        
    }
    
}

int main(){
  string open = "(((";
  string close = ")))";
  string str = "";
  if(open.size() == close.size())
    paranthesis(open, close, str);
  
}
