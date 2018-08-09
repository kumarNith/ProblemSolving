#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> result;
    if(n % (2*k)){
        result.push_back(-1);
        return result;
    }
    int loop = n / (2*k);
    int perm;
    for (int i = 0; i < loop; i++){
        for(int j = 1; j <= k; j++){
            perm = (i*2*k) + j + k;
            result.push_back(perm);
        }
        for(int j = 1; j <= k; j++){
            perm = (i*2*k) + j;
            result.push_back(perm);
        }
    }
    return result;
}

int main(){
    int n,k;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Enter k"<<endl;
    cin>>k;
    vector<int> result;
    result = absolutePermutation(n,k);
    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;
}
