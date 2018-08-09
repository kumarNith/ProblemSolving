#include<iostream>
#include<vector>
#include<string>
int k;
using namespace std;

//int mulHelperUtil()

int mulHelper(int m, int n){
	k++;
	if (k > 50)
		return -1;
	int result = 1;
	cout<<"m is "<<m<<" , n is "<<n<<endl;
	if(m == 0 || n == 0)
		return 0;
	if(m == 1)
		return n;
	if (n == 1)
		return m;

	int bigger = m > n ? m : n;
	int smaller = m > n ? n : m;
	//int temp = 1;
	result = bigger;
	int tick = 1;
	while(smaller >=  (tick + tick)){
		result <<= 1;
		tick <<= 1;
	}

	result += mulHelper(bigger, smaller - tick);

	return result;
}

int main(){
	int m,n;
	cout<<"Enter the m"<<endl;
	cin>>m;
	cout<<"Enter the n"<<endl;
	cin>>n;
	cout<<mulHelper(m,n)<<endl;
	return 0;
}