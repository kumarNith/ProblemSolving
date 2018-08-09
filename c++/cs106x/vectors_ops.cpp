#include<iostream>
#include<string>
#include<vector>

using namespace std;

void vectorOps(vector<int> &v){
	cout<<"Size of the vector : "<<v.size()<<endl;
	v.push_back(2);
	cout<<"(Expected size is 2) Size of the vector : "<<v.size()<<endl;
	v.pop_back();
	cout<<"(Expected size is 1) Size of the vector : "<<v.size()<<endl;

	vector<int> v1(6);// = {1,2,3,4,5,6};
	
	for (unsigned i = 0; i < v1.size(); i++){
		v1.at(i) = i * 2;
	}

   for (unsigned i = 0; i < v1.size(); i++){
       cout<<v1.at(i)<<" ";
   }
	cout<<endl;
	
	cout<<v1.back()<<endl;
	cout<<"(Expected size is 6) Size of the vector : "<<v1.size()<<endl;
	
	v1.pop_back();
	cout<<"(Expected size is 5) Size of the vector : "<<v1.size()<<endl;
	v1.at(0) = 1;
	cout<<"Iterator test"<<endl;
	vector<int>::iterator it = v1.begin();
    for (;it != v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Size of v1 : "<<v1.size()<<endl;
    cout<<"Capacity of v1 : "<<v1.capacity()<<endl;
    cout<<"max_size : "<<v1.max_size()<<endl;
}

int main(){
	vector<int> v = {1};
	vectorOps(v);
	return 0;
}