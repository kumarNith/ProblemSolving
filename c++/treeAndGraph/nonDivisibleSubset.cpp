// Example program
#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
    int size = S.size();
    int arr[k] = {0};
    int result = 0;
    
    for(int i : S){
        arr[i%k] += 1;
    }
    for (int i =1; i <k/2; i++){
        result += max(arr[i], arr[k-i]);
    }
    
    if(k > 1){
        if(k % 2){
            result += max(arr[k/2], arr[(k/2)+1]);
        }
        else
            result += min(arr[k/2], 1);
    }
    
    result += min(arr[0], 1);
    return result;
}

int main()
{
  int k = 1;
  vector<int> S = {1,2,3,4,5};
  cout<<nonDivisibleSubset(k, S)<<endl;
}