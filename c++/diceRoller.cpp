/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int count = 0;

void diceSumHelper(int n, int target, vector<int> &v, int sumSoFar){
    count++;
//cout<<n<<" " <<sum<<" "<<endl; 
if( n == 0 ){
    if(target == sumSoFar){
        //v.push_back();
        for (int i : v){
            cout<<i;
        }
        cout<<endl;
    }
}
else{
    for (int i = 1; i <= 6; i++)    {
        int min = sumSoFar + (n * 1);
        int max = sumSoFar + (n*6);
        if(min <= target && max >= target){
        //if(((sumSoFar+i) <= target) && (n*6 + sumSoFar >= target)){
        //if(1){
            v.push_back(i);
            diceSumHelper(n-1,target,v,sumSoFar + i);
            v.pop_back();
        }
    }
}


}


void diceSum(int n, int target){
    vector<int> v;
    diceSumHelper(n, target, v, 0);
}


int main(){
    int numOfDice = 3;
    int target = 5;
    diceSum(numOfDice, target);
    cout<<"count is "<<count;
    return 0;
}
