#include<iostream>
using namespace std;

/*
 * Complete the divisors function below.
 */
int divisors(int n) {
    /*
     * Write your code here.
     */
    int count = 0;
    int i = 1;
    if(n % 2 == 1)
        return 0;
    while(i * 2 <= n){
        if( n % (2 * i++) == 0){
            count++;
        }
    }

    return count;
}

int divisors_optimized(int n) {
    if(n % 2 == 1)
        return 0;
    int count = 0;
    int i = 1;
    //int k;
    for(; i * i <= n; i++){
        if( n % i == 0 && i % 2 == 0)
            count++;

        if(n % i == 0 && ((n/i)%2 == 0))
            count++;
    }
    return count;
}

int main(){
    int x;
    cout<<"Enter the number : "<<endl;

    cin>>x;
    cout<<divisors(x)<<endl;
    cout<<divisors_optimized(x)<<endl;
}