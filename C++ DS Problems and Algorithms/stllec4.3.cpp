#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char s[100]="Today is rainy day";

    char *ptr=strtok(s," ");
    cout<<ptr<<" ";
    while(ptr!=NULL){
    ptr=strtok(NULL," ");
    cout<<ptr<<" ";
    }

    return 0;
}
