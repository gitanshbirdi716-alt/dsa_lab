#include<iostream>
using namespace std;
const int MAX=100;
int arr[MAX];
int size=0;
void create() {

    cout << "Enter number of elements: ";
    cin >> size;
    if (size > MAX) {
        cout << "Size exceeds limit\n";
        size = 0;
        return;
    }
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully\n";
}
void display() {
    if (size == 0) {
        cout << "Array is empty"<<endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void insert() {
    if (size == MAX) {
        cout << "Array is full"<<endl;
        return;
    }
    int pos, val;
    cout << "Enter position (0 to " << size << "): ";
    cin >> pos;
    if (pos < 0 || pos > size) {
        cout << "Invalid position"<<endl;
        return;
    }
    cout << "Enter value: ";
    cin >> val;
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
    cout << "Element inserted"<<endl;
}

void deleteElement() {
    if (size == 0) {
        cout << "Array is empty"<<endl;
        return;
    }
    int pos;
    cout << "Enter position (0 to " << size - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position"<<endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted"<<endl;
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty"<<endl;
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found"<<endl;
}

int main() {
    int choice;
    while (true) {
        cout << "MENU"<<endl;
        cout << "1. CREATE 2.DISPLAY  3. INSERT  4. DELETE  5. LINEAR SEARCH  6. EXIT  "<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting"<<endl; return 0;
            default: cout << "Invalid choice"<<endl;
        }
    }
}



