#include<iostream>
#include<string>
#include<stack>
#include<vector>

int i;
using namespace std;
/*
void towerOfHanai(stack<int> s1, int n){
	

}*/

stack<int> towerOfHanai(stack<int> s1, int n){
	stack<int> s2;
	stack<int> s3;

	s2.push(s1.top());
	s1.pop();
	s3.push(s1.top());
	s1.pop();
	while(s3.size() != n){
		cout<<++i<<endl;
		if(s1.size() && (s1.top() < s2.top() || s2.empty()) ){
			cout<<" **1 "<<endl;
			s2.push(s1.top());
			s1.pop();
		}
		if(s1.size() && (s1.top() < s3.top() || s2.empty())){
			cout<<" **2 "<<endl;
			s3.push(s1.top());
			s1.pop();
		}

		if(s2.size() && (s2.top() < s3.top() || s3.empty())){
			cout<<" **3 "<<endl;
			s3.push(s2.top());
			s2.pop();
		}
		if(s2.size() && (s2.top() < s1.top() || s3.empty())){
			cout<<" **4 "<<endl;
			s1.push(s1.top());
			s2.pop();
		}
		if(s3.size() && (s3.top() < s1.top() || s1.empty())){
			cout<<" **5 "<<endl;
			s1.push(s3.top());
			s2.pop();
		}
		if(s3.size() && (s3.top() < s2.top() || s1.empty())){
			cout<<" **6 "<<endl;
			s2.push(s3.top());
			s2.pop();
		}

	}
	return s3;
}

int main(){
	stack<int> s1;
	stack<int> s2;
	stack<int> s3;

	int n;
	cout<<"Enter the no of towers : "<<endl;
	cin>>n;
	for (int i = 3; i >0; i--){
		s1.push(i);
	}
	s3 = towerOfHanai(s1, n);
	while(s3.size()){
		cout<<s3.top()<<endl;
		s3.pop();
	}
	return 0;
}


/*


stack<int> towerOfHanai(stack<int> s1, int n){
	stack<int> s2;
	stack<int> s3;
	
	s2.push(s1.top());
	s1.pop();
	s3.push(s1.top());
	s1.pop();
	while(s3.size() != n){
		cout<<++i<<endl;
		if(s1.size() && (s1.top() < s2.top() || s2.empty()) ){
			cout<<" **1 "<<endl;
			s2.push(s1.top());
			s1.pop();
		}
		if(s1.size() && (s1.top() < s3.top() || s2.empty())){
			cout<<" **2 "<<endl;
			s3.push(s1.top());
			s1.pop();
		}

		if(s2.size() && (s2.top() < s3.top() || s3.empty())){
			cout<<" **3 "<<endl;
			s3.push(s2.top());
			s2.pop();
		}
		if(s2.size() && (s2.top() < s1.top() || s3.empty())){
			cout<<" **4 "<<endl;
			s1.push(s1.top());
			s2.pop();
		}
		if(s3.size() && (s3.top() < s1.top() || s1.empty())){
			cout<<" **5 "<<endl;
			s1.push(s3.top());
			s2.pop();
		}
		if(s3.size() && (s3.top() < s2.top() || s1.empty())){
			cout<<" **6 "<<endl;
			s2.push(s3.top());
			s2.pop();
		}

	}
	return s3;
}

*/