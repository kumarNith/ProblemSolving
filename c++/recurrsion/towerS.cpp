#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void towerOfHanai(int n , stack<int> &from, stack<int> &to, stack<int> &buff){
	if(n == 1){
		cout<<"moving disk 1 , size of from :"<<from.size()<<endl;//<<from<<" to "<<to<<endl;
		to.push(from.top());
		from.pop();
		return;
	}
	towerOfHanai(n-1,  from,  buff, to);
	cout<<"moving disk "<<n<<" ,size of from :"<<from.size()<<endl;//" from "<<from<<" to "<<to<<endl;
	to.push(from.top());
	from.pop();
	towerOfHanai(n-1, buff, to, from);	
}

int main(){
	int n;
	cout<<"Enter the number of disks : "<<endl;
	cin>>n;
	stack<int> s1;
	stack<int> s2;
	stack<int> s3;
	for (int i = n; i > 0; i--)
		s1.push(i);
	cout<<"s1 size : "<<s1.size()<<endl;
	cout<<"s2 size : "<<s2.size()<<endl;
	cout<<"s3 size : "<<s3.size()<<endl;
	cout<<"Starting the tower Game"<<endl;
	towerOfHanai(n,s1, s3, s2);
	cout<<"s3 size : "<<s3.size()<<endl;
	cout<<"s2 size : "<<s2.size()<<endl;
	cout<<"s1 size : "<<s1.size()<<endl;
	cout<<"Now s3 size : "<<s3.size()<<endl;
	for(int i = 0; i < n; i++){
		cout<<s3.top()<<endl;
		s3.pop();
	}
	return 0;
}

