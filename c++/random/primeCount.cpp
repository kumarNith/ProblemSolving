#include<iostream>
#include<vector>

using namespace std;

int primeCount(long n) {
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    long mul = 1;
    int count = 0;
    cout<<"target is "<<n<<endl;
    if (n < 2)
        count = 0;
    else if(n < 6)
        count = 1;
    else{
        for(int i : prime){
            
            cout<<"mul is "<<mul<<" ,count is - "<<count<<" , i is "<<i<<endl;
            mul *= i;
            if(mul > n){
                cout<<"Going to break : mul is "<<mul<<" ,count is - "<<count<<endl;
                break;
            }
            count++;
        }
    }
    
    return count;
    /*
     * Write your code here.
     */

}

int main(){

    int x;
    cout<<"Enter x"<<endl;
    cin>>x;
    cout<<primeCount(x)<<endl;

    return 0;
}