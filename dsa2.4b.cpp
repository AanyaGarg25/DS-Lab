#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s1[50],s2[50];

    cout<<"Enter 1st string"<<endl;
    cin>>s1;

    int n=strlen(s1);


    for (int i=0;i<n;i++){
        s2[i]=s1[n-1-i];
    }
 
    s2[n]='\0';

    cout<<s2<<endl;
    return 0;

}
