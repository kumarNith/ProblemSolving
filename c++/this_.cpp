#include<iostream>
using namespace std;
class Box{
	public:
		long l;
		long b;
		long h;
		static int objectCount;
		
	    Box(long l1, long b1, long h1){
		this->l = l1;
		this->b = b1;
		this->h = h1;
		objectCount++;
	}
	double volume(){
		return l*b*h;
	}
	bool compare(Box test){
		return this->volume() > test.volume();
	}
};
int main(){
	Box A(3,4,5);
	cout<<"A :: objectcount "<<Box::objectCount<<endl;
	Box B(3,3,61);
	cout<<"B :: objectcount "<<Box::objectCount<<endl;
	if (A.compare(B))
		cout<<"Box A is greater than Box B"<<endl;
	else
		cout<<"Box B is greater than Box A"<<endl;
	return 0; 
}
