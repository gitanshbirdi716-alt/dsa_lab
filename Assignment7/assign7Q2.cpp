#include<iostream>
using namespace std;
void improvedsort(int arr[], int n) {
    int s = 0, e = n - 1;
    while (s < e) {
        int minind = s;
        int maxind = s;
        for (int i = s; i <= e; i++) {
            if (arr[i] < arr[minind]) minind = i;
            if (arr[i] > arr[maxind]) maxind = i;
        }
        swap(arr[s], arr[minind]);
        if (maxind == s) maxind = minind;
        swap(arr[e], arr[maxind]);
        s++;
        e--;
    }
    cout << "sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int arr[6] = {7, 9, 2, 8, 5, 3};
    int n = 6;
    cout << "original array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    improvedsort(arr, n);
    return 0;
}
