#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    double A[100]; 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int inversionCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                inversionCount++;
                cout << "Inversion: (" << A[i] << ", " << A[j] << ")" << endl;
            }
        }
    }

    cout << "Total number of inversions = " << inversionCount << endl;

    return 0;
}

