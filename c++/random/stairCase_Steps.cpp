#include<iostream>
#include<string>

using namespace std;

void findPossibleStepsCombination( int n, int ss, string steps){

	if(n - ss >= 0){
		//char ch = ss;
		steps+=to_string(ss);
		if(n -ss ==0){
			cout<<steps<<endl;
			return;
		}
	}
	if(n < 0)
		return;


	findPossibleStepsCombination(n-ss, 1, steps);
	findPossibleStepsCombination(n-ss, 2, steps);
}

void findPossibleSteps( int n, string steps){
	findPossibleStepsCombination(n, 1, " ");
	findPossibleStepsCombination(n, 2, " ");
} 

int main(){
	int n = 5;

	string steps;// = "";
	findPossibleSteps(n, steps);
}