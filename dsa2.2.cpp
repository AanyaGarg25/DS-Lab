#include<iostream>
using namespace std;
int main(){
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
    return 0;
}
