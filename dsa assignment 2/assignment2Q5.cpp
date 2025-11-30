#include <iostream>
using namespace std;

int main() {
    int n, choice;
    cout << "Enter order of square matrix (n x n): ";
    cin >> n;

    cout << "Choose matrix type:\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cin >> choice;

    if (choice == 1) {
        // (a) Diagonal Matrix 
        int diag[1][n];
        cout << "Enter " << n << " diagonal elements:\n";
        for (int i = 0; i < n; i++) cin >> diag[0][i];

        cout << "Diagonal Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << diag[0][i] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 2) {
        // (b) Tri-diagonal Matrix 
        int tri[3][n]; 
        cout << "Enter elements:\n";
        cout << "Main diagonal (" << n << "): ";
        for (int i = 0; i < n; i++) cin >> tri[1][i];
        cout << "Lower diagonal (" << n - 1 << "): ";
        for (int i = 0; i < n - 1; i++) cin >> tri[0][i];
        cout << "Upper diagonal (" << n - 1 << "): ";
        for (int i = 0; i < n - 1; i++) cin >> tri[2][i];

        cout << "Tri-diagonal Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << tri[1][i] << " ";
                else if (i - j == 1) cout << tri[0][j] << " ";
                else if (j - i == 1) cout << tri[2][i] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 3) {
        // (c) Lower Triangular Matrix 
        int lower[n][n];
        cout << "Enter elements for lower triangular matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> lower[i][j];
            }
        }

        cout << "Lower Triangular Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j <= i) cout << lower[i][j] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 4) {
        // (d) Upper Triangular Matrix 
        int upper[n][n];
        cout << "Enter elements for upper triangular matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cin >> upper[i][j];
            }
        }

        cout << "Upper Triangular Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= i) cout << upper[i][j] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 5) {
        // (e) Symmetric Matrix 
        int sym[n][n];
        cout << "Enter elements for lower triangular part of symmetric matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> sym[i][j];
                sym[j][i] = sym[i][j]; 
            }
        }

        cout << "Symmetric Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sym[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

