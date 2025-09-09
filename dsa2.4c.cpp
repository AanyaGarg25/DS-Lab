#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s1[50],s2[50];

    cout<<"Enter  string  : "<<endl;
    cin>>s1;

    int n=strlen(s1);
    int j=0;

    for(int i=0;i<n;i++){
        if(s1[i]!='a'&& s1[i]!='e'&& s1[i]!='i'&& s1[i]!='o'&&
        s1[i]!='u'&& s1[i]!='A'&& s1[i]!='E'&& s1[i]!='I'&& s1[i]!='O'&& s1[i]!='U'){
            s2[j++]=s1[i];
        }
 
    }
    s2[n]='\0';
    cout<<s2<<endl;
    return 0;
}
