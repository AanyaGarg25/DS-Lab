#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int arr[1000];
    int k = 0;
    cout << "Enter " << n*(n+1)/2 << " elements row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Upper Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)
                cout << arr[k++] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
