#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* str1, char* str2){
	char *temp = str1;
	str1 = str2;
	str2 = temp;
}

int main(){
    char* s1 = "Hello";
    char* s2 = "World";
    swap(s1,s2);
    printf("str1 is %s str2 is %s \n", s1, s2);
	return 0;
}