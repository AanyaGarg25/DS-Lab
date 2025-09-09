#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int arr[1000];
    int k = 0;
    cout << "Enter " << n*(n+1)/2 << " elements (upper triangular row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Symmetric Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)
                cout << arr[(i*n - (i*(i-1))/2) + (j-i)] << " ";
            else
                cout << arr[(j*n - (j*(j-1))/2) + (i-j)] << " ";
        }
        cout << endl;
    }
    return 0;
}
