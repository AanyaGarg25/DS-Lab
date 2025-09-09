#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many elements you want in an array: ";
    cin >> n;

    int arr[n];  

  
    for (int i = 0; i < n; i++) {
        cout << "Enter element : ";
        cin >> arr[i];
    }

 
    cout << "Array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int num;
    cout<<"enter the number you want to search"<<endl;
    cin>>num;

    int f=0;
    int l=n-1;
    

    while(f<=l){
        int m=(f+l)/2;
        if(arr[m]>num){
            l=m-1;
            
        }

        else if(arr[m]<num){
            f=m+1;
                
        }

        else{
            cout<<"the element to be searched is at "<<m;
            break;
        }
    }
    return 0;

}
