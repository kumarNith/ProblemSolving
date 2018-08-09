// Example program
#include <iostream>
#include <string>
using namespace std;
 


int evaluate(string exp);
int evaluateHelper(string exp, int& index);




int evaluateHelper(string exp, int& index){
    //cout<<index<<endl;
    if(isdigit(exp[index])){
        return exp[index] - '0';
    }
    else{
        index++;
        int left = evaluateHelper(exp,index);
        index++;
        char op = exp[index];
        index++;
        int right = evaluateHelper(exp,index);
        index++;
        int result;
        if (op == '+')
            result =  left + right;
        else if (op == '-')
            result =  left -right;
        else if (op == '*')
            result =  left * right; 
        else
            result =  left/right;
        return result;
    } 
}


int evaluate(string exp){
    int index = 0;
    return evaluateHelper(exp,index);
}

int main()
{
  string exp = "(2+((4-(2*5))+(8*3)))";
  cout<<evaluate(exp);
}
