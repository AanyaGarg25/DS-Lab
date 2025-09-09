#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter how many element you want";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter n consecutive element : ";
        cin >> arr[i];
    } 
    cout << "Array is: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int sum=((n+1)*(n+2))/2;

    int act_sum=0;
    for(int i=0;i<n;i++){
        act_sum+=arr[i];
    }

    int missing=sum-act_sum;
    cout<<"missing number is :"<<missing;
    return 0;
}

