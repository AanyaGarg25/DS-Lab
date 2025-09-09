#include <iostream>
using namespace std;

int main() {
    int m, n, t1, t2;

    cout << "Enter rows and cols of first matrix: ";
    cin >> m >> n;
    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> t1;

    int A[t1 + 1][3]; 
    A[0][0] = m; A[0][1] = n; A[0][2] = t1;

    cout << "Enter row col value (triplet form):\n";
    for (int i = 1; i <= t1; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    cout << "Enter rows and cols of second matrix: ";
    cin >> m >> n;
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> t2;

    int B[t2 + 1][3]; 
    B[0][0] = m; B[0][1] = n; B[0][2] = t2;

    cout << "Enter row col value (triplet form):\n";
    for (int i = 1; i <= t2; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    // a) transpose 
    int T[t1 + 1][3];
    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];

    int k = 1;
    for (int col = 0; col < A[0][1]; col++) {
        for (int i = 1; i <= t1; i++) {
            if (A[i][1] == col) {
                T[k][0] = A[i][1];
                T[k][1] = A[i][0];
                T[k][2] = A[i][2];
                k++;
            }
        }
    }

    cout << "\nTranspose of first matrix:\n";
    for (int i = 0; i <= T[0][2]; i++) {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }

    // addition 
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "\nAddition not possible (different dimensions)\n";
    } else {
        int C[t1 + t2 + 1][3];
        C[0][0] = A[0][0];
        C[0][1] = A[0][1];
        int i = 1, j = 1, l = 1;

        while (i <= t1 && j <= t2) {
            if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
                C[l][0] = A[i][0];
                C[l][1] = A[i][1];
                C[l][2] = A[i][2];
                i++; l++;
            } else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
                C[l][0] = B[j][0];
                C[l][1] = B[j][1];
                C[l][2] = B[j][2];
                j++; l++;
            } else { 
                int sum = A[i][2] + B[j][2];
                if (sum != 0) {
                    C[l][0] = A[i][0];
                    C[l][1] = A[i][1];
                    C[l][2] = sum;
                    l++;
                }
                i++; j++;
            }
        }

        while (i <= t1) {
            C[l][0] = A[i][0];
            C[l][1] = A[i][1];
            C[l][2] = A[i][2];
            i++; l++;
        }
        while (j <= t2) {
            C[l][0] = B[j][0];
            C[l][1] = B[j][1];
            C[l][2] = B[j][2];
            j++; l++;
        }

        C[0][2] = l - 1;

        cout << "\nAddition Result:\n";
        for (int p = 0; p <= C[0][2]; p++) {
            cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
        }
    }

    // multiplication 
    if (A[0][1] != B[0][0]) {
        cout << "\nMultiplication not possible (dimension mismatch)\n";
    } else {
        int M[100][3]; 
        M[0][0] = A[0][0];
        M[0][1] = B[0][1];
        int l = 1;

        for (int i = 0; i < A[0][0]; i++) {
            for (int j = 0; j < B[0][1]; j++) {
                int sum = 0;
                for (int p = 1; p <= t1; p++) {
                    if (A[p][0] == i) {
                        for (int q = 1; q <= t2; q++) {
                            if (B[q][0] == A[p][1] && B[q][1] == j) {
                                sum += A[p][2] * B[q][2];
                            }
                        }
                    }
                }
                if (sum != 0) {
                    M[l][0] = i;
                    M[l][1] = j;
                    M[l][2] = sum;
                    l++;
                }
            }
        }
        M[0][2] = l - 1;

        cout << "\nMultiplication Result:\n";
        for (int p = 0; p <= M[0][2]; p++) {
            cout << M[p][0] << " " << M[p][1] << " " << M[p][2] << endl;
        }
    }

    return 0;
}
