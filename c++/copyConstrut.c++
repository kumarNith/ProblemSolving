#include<iostream>
#include<vector>

using namespace std;
int h = 3;

class Box{
public:
	int length;
	int breath;
	int area();
	~Box();
};

int Box::area(){

	return this->length*this->breath*h;
	//return length*breath;
}

Box::~Box(){
	cout<<"Deleting the box object"<<endl;
}

int main(){
	Box box1;
	box1.length = 3;
	box1.breath = 4;
	//Box box2 = box1;
	cout<<"Area of box1 is : "<<box1.area()<<endl;
	Box box2 = box1;
	cout<<"Area of box2 is : "<<box2.area()<<endl;
	box1.length = 30;
	box1.breath = 40;
	cout<<"Area of box1 is : "<<box1.area()<<endl;
	cout<<"Area of box2 is : "<<box2.area()<<endl;
}
