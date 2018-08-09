#include<iostream>
#include<string>
#include <cstring>
using namespace std;
void urlify(const string &url)
{
	int length = url.length();
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if(url[i] == ' ')
			count++;	
	}
	
	int newspace = length + (count *2) + 1;
	char new_url[newspace];
	int j = 0;
	memset(new_url, 0, sizeof(new_url));
	for (int i = 0; i < length; i++)
	{
		if(url[i] == ' '){
			new_url[j++] = '%';
			new_url[j++] = '2';
			new_url[j++] = '0';
		}
		else{
			new_url[j++] = url[i];
			//j++; 
		}
	}
    new_url[j] = '\0';
	cout<<new_url<<endl;
	
}

int main(){
//char str[] = "Mr John Smith"; 
urlify("Mr John Smith");

return 0;
}
