#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the length of array: ";
    cin >> n;

    int arr[100];  // fixed size for simplicity
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;   // duplicate found
            }
        }
        if (j == i) {  // no duplicate before index i
            count++;
        }
    }
    cout << "Number of distinct elements is: " << count << endl;
    return 0;
}
