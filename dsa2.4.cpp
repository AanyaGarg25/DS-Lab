#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s1[50],s2[50];
    cout<<"Enter 1st string"<<endl;
    cin>>s1;
 
    cout<<"enter 2nd string"<<endl;
    cin>>s2;
 
    strcat(s1,s2);
    cout<<s1<<endl;
    return 0;

}
