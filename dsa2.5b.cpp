#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int arr[300]; 
    cout << "Enter elements (lower, main, upper diagonals):\n";
    for (int i = 0; i < 3*n-2; i++) {
        cin >> arr[i];
    }

    cout << "Tri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) 
                cout << arr[n-1 + i] << " ";
            else if (i == j+1) 
                cout << arr[j] << " ";
            else if (j == i+1) 
                cout << arr[2*n-1 + i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
