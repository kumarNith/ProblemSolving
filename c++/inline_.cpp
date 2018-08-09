#include<iostream>

using namespace std;
inline int max_(int x, int y){
	return (x > y ? x : y);
}
int main(){
	cout<<"max(5 ,7 ) " <<max_(5,7)<<endl;
	cout<<"max(-5 ,-7 ) " <<max_(-5,-7)<<endl;
}