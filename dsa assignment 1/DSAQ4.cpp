#include <iostream>
using namespace std;

// Function to reverse an array
void reverseArray() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100]; // max size fixed
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Reverse logic
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to transpose a matrix
void transposeMatrix() {
    int rows, cols;
    cout << "Enter rows and columns of matrix: ";
    cin >> rows >> cols;

    int A[10][10], T[10][10]; // fixed max size

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    // Transpose logic
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }

    cout << "Transpose of matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to multiply two matrices
void multiplyMatrix() {
    int m, n, p;
    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int A[10][10], B[10][10], C[10][10];

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplication logic
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix C:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Call the functions one by one
    reverseArray();
    transposeMatrix();
    multiplyMatrix();
    return 0;
}
