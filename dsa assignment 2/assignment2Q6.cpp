#include <iostream>
using namespace std;

#define MAX 100

// Function to print triplet form
void printSparse(int mat[MAX][3]) {
    int n = mat[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

// Convert normal matrix to sparse matrix
void toSparse(int normal[10][10], int r, int c, int sparse[MAX][3]) {
    int k = 1; // index for triplet
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (normal[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = normal[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = k - 1; // total nonzero
}

// (a) Transpose
void transpose(int s[MAX][3], int t[MAX][3]) {
    int rows = s[0][0], cols = s[0][1], n = s[0][2];
    t[0][0] = cols;
    t[0][1] = rows;
    t[0][2] = n;

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= n; i++) {
            if (s[i][1] == col) {
                t[k][0] = s[i][1];
                t[k][1] = s[i][0];
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
}

// (b) Addition
void addSparse(int s1[MAX][3], int s2[MAX][3], int sum[MAX][3]) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        cout << "Matrices cannot be added\n";
        return;
    }
    int i = 1, j = 1, k = 1;
    sum[0][0] = s1[0][0];
    sum[0][1] = s1[0][1];

    while (i <= s1[0][2] && j <= s2[0][2]) {
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1])) {
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2];
            i++; k++;
        }
        else if (s2[j][0] < s1[i][0] || (s1[i][0] == s2[j][0] && s2[j][1] < s1[i][1])) {
            sum[k][0] = s2[j][0];
            sum[k][1] = s2[j][1];
            sum[k][2] = s2[j][2];
            j++; k++;
        }
        else { // same row & col
            sum[k][0] = s1[i][0];
            sum[k][1] = s1[i][1];
            sum[k][2] = s1[i][2] + s2[j][2];
            i++; j++; k++;
        }
    }
    while (i <= s1[0][2]) {
        sum[k][0] = s1[i][0];
        sum[k][1] = s1[i][1];
        sum[k][2] = s1[i][2];
        i++; k++;
    }
    while (j <= s2[0][2]) {
        sum[k][0] = s2[j][0];
        sum[k][1] = s2[j][1];
        sum[k][2] = s2[j][2];
        j++; k++;
    }
    sum[0][2] = k - 1;
}

// (c) Multiplication
void multiplySparse(int s1[MAX][3], int s2[MAX][3], int result[MAX][3]) {
    if (s1[0][1] != s2[0][0]) {
        cout << "Matrices cannot be multiplied\n";
        return;
    }

    int r1 = s1[0][0], c1 = s1[0][1], c2 = s2[0][1];
    int temp[10][10] = {0};

    for (int i = 1; i <= s1[0][2]; i++) {
        for (int j = 1; j <= s2[0][2]; j++) {
            if (s1[i][1] == s2[j][0]) {
                temp[s1[i][0]][s2[j][1]] += s1[i][2] * s2[j][2];
            }
        }
    }

    toSparse(temp, r1, c2, result);
}

int main() {
    int r1, c1, r2, c2;
    int normal1[10][10], normal2[10][10];
    int s1[MAX][3], s2[MAX][3], t[MAX][3], sum[MAX][3], prod[MAX][3];

    cout << "Enter rows and cols of matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> normal1[i][j];

    cout << "Enter rows and cols of matrix 2: ";
    cin >> r2 >> c2;
    cout << "Enter elements of matrix 2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> normal2[i][j];

    // Convert to sparse
    toSparse(normal1, r1, c1, s1);
    toSparse(normal2, r2, c2, s2);

    cout << "\nSparse Matrix 1:\n";
    printSparse(s1);
    cout << "\nSparse Matrix 2:\n";
    printSparse(s2);

    // (a) Transpose
    transpose(s1, t);
    cout << "\nTranspose of Matrix 1:\n";
    printSparse(t);

    // (b) Addition
    addSparse(s1, s2, sum);
    cout << "\nAddition (if possible):\n";
    printSparse(sum);

    // (c) Multiplication
    multiplySparse(s1, s2, prod);
    cout << "\nMultiplication (if possible):\n";
    printSparse(prod);

    return 0;
}

