#include <iostream>
using namespace std;
int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
  int A[10][10];
 cout << "Enter elements of matrix"<<endl;
for (int i = 0; i < r; i++) {
  for (int j = 0; j < c; j++) {
    cin >> A[i][j];
   }
}
 cout << "\nSum of each row"<<endl;
 for (int i = 0; i < r; i++) {
 int rowsum = 0;
 for (int j = 0; j < c; j++) {
 rowsum =rowsum + A[i][j];
    }
 cout << "Row " << i + 1 << " = " << rowsum << endl;
    }
 cout << "Sum of each column"<<endl;
 for (int j = 0; j < c; j++) {
 int colsum = 0;
 for (int i = 0; i < r; i++) {
	colsum =colsum + A[i][j];
}
cout << "Column " << j + 1 << " = " << colsum << endl;
    }

   return 0;
}

