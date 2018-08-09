// Example program
#include <iostream>
#include <string>
using namespace std;

void printBinary(int digits, string prefix){
    if(digits == 0)
        cout<<prefix<<endl;
    else{
        printBinary(digits-1, prefix + "0");
        printBinary(digits-1, prefix + "1");
    }
}
int main()
{
  printBinary(3," ");
  return 0;
}