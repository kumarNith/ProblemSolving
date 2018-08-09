#include<iostream>
#include<vector>

using namespace std;

void towerOfHanai(int n , char from, char to, char buff){
	if(n == 1){
		cout<<"moving disk 1 from "<<from<<" to "<<to<<endl;
		return;
	}
	towerOfHanai(n-1, from, buff, to);
	cout<<"moving disk "<<n<<" from "<<from<<" to "<<to<<endl;
	towerOfHanai(n-1, buff, to, from);	
}

int main(){
	int n;
	cout<<"Enter the number of disks : "<<endl;
	cin>>n;
	towerOfHanai(n,'A', 'C', 'B');
}

