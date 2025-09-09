#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s1[50];

    cout<<"Enter  string  : "<<endl;
    cin>>s1;

    int n=strlen(s1);
 
    for(int i=0;i<n;i++){
        if (s1[i]<=90 && s1[i]>=65){
            s1[i]+=32;
        }
    }
 
    s1[n]='\0';
    cout<<s1<<endl;
    return 0;
}
