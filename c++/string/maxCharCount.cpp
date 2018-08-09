#include<iostream>
#include<string>
#include<vector>

#define ASCII 256

using namespace std;
void maxOccuringChar(string str){
	int len = str.length();
	int count[ASCII] = {0};
	for (int i = 0; i < len; i++){
		count[str[i]]++;
	}
	int max = -1;
	char max_ch;
	for (int i = 0; i < ASCII; i++){
		if (max < count[i]){
			max = count[i];
			max_ch = i;
		}
	}
	cout<<"max occuring char "<<max_ch<<" , occured "<<max<<endl;
}

int main(){
	string str = "Nithya Palanikumar";
	maxOccuringChar(str);
	return 0;
}