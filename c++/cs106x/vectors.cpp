#include<iostream>
#include<string>
#include<vector>
using namespace std;
void vectorOps(vector <int> &v ){
    cout<<v.size()<<endl;
    v.push_back(60);
    cout<<v[5]<<endl;
    cout<<"Now size is : "<<v.size()<<endl;
    int x = v.pop_back();
    cout<<"pop_back returns :"<<x<<endl;
    cout<<"Size after pop_back() : "<<v.size()<<endl;
}

int main(){
	vector <int> v = {1,2,3,4,5};
	vectorOps(v);
	//cout<<s1;
	return 0;
}