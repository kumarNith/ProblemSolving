#include<iostream>
#include<vector>

using namespace std;

class Shape{
	public:
		int l = 10;
		int b = 10;
		virtual int area() = 0;
		//void area() ;
};

class Square: Shape{
    public:
	int area(){
		cout<<l<<" , "<<b<<endl;
		return l*b;
	}
};
int main(){
	Square sqr;
	cout<<"Area of a square "<<sqr.area()<<endl;
	return 0;
}