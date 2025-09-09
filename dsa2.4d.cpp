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
       
       if (s1[i]<=90 && s1[i]>=65){
           
           s1[i]+=32;
        }
    }
        for(int i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s1[i]>s1[j]){
                int temp=s1[i];
                s1[i]=s1[j];
                s1[j]=temp;
            }
        }
    }    
    s1[n]='\0';
    cout<<s1<<endl;
    return 0; 
}
