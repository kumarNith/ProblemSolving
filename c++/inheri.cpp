include<iostream>
using namespace std;

class Shape{
	protected:
		int l;
		int b;
	public:
		void setLength(int length){
			l = length;
		}
		void setBreadth(int breadth){
			b = breadth;
		}
}

class Rectangle: public Shape{
	public:
		int calculateArea(){
		return i*b;
		}
}

int main(){
	Rectangle A;
	A.setLength(10);
	A.setBreadth(6);
	cout<<"Area is "<<A.calculateArea()<<endl;
	
}