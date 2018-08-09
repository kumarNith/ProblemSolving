#include<iostream>
#include<string>

using namespace std;

string ones[] = {
	    "zero", "one", "two", "three", "four", "five", "six",
	    "seven", "eight", "nine", "ten", "eleven", "twelve",
	    "thirteen", "fourteen", "fifteen", "sixteen",
	    "seventeen", "eighteen", "nineteen"};

	string twos[] = {
	    "zero","ten", "twenty", "thirty", "forty", "fifty", "sixty",
	    "seventy", "eighty", "ninety"};


string alpha2string(int n){
	if(n >= 100)
		return "None";
	string str = "";
	if(n < 20)
		str = ones[n];
	else{
		int second = n / 10;
		int first = n % 10;
		if(!first)
			str = twos[second];
		else
			str += twos[second];
			str += " ";
			str += ones[first];
	}
	return str;
}

string timeInWords(int h, int m){
	string hour = alpha2string(h);
	string minutes = alpha2string(m);
	string time;
	if(m == 0){
		time = ones[h] + " o' clock";

	}
	else if (m == 15){
		time = "quater past " + ones[h];

	}
	else if (m == 30){
		time = "half past " + ones[h];

	}
	else if(m < 30){
		if(m == 1){
			time = "one minute past "+ ones[h];
		}
		else{
			string mins = alpha2string(m);
			time = mins +  " minutes past " + ones[h];
		}
	}
	else{
		//cout<<"Last section "<<endl;
		if(m == 45){
			if (h == 12)
				time = "quater to one";
			else
				time = "quater to " + 	ones[h+1];
		}
		else if(m == 59){
			if (h == 12)
				time = "one minute to one";
			else
				time = "one minute to " + 	ones[h+1];
		}
		else{
			m = 60 - m;
			string mins = alpha2string(m);

			if (h == 12)
				time = mins + " minutes to one";
			else
				time = mins + " minutes to " + 	ones[h+1];
		}
	}

	return time;
}

int main(){
	/*int n;
	cout<<"Enter a number between 0 to 99"<<endl;
	cin>>n;*/
	int h;int m;

	cout<<"Enter hour"<<endl;
	cin>>h;
	cout<<"Enter minutes"<<endl;
	cin>>m;


	cout<<"Answer is : "<<timeInWords(h,m)<<endl;
	return 0;
}

