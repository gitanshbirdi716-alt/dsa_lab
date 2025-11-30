#include <iostream>
using namespace std;

void maxheap(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheap(arr, n, largest);
    }
}

void minheap(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
        smallest = left;
    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minheap(arr, n, smallest);
    }
}

void incsort(int arr[], int n)
{
    while (n > 1)
    {
        swap(arr[1], arr[n]);
        n--;
        maxheap(arr, n, 1);
    }
}

void decsort(int arr[], int n)
{
    while (n > 1)
    {
        swap(arr[1], arr[n]);
        n--;
        minheap(arr, n, 1);
    }
}

int main()
{
    int arr1[6] = {-1, 1, 6, 3, 2, 8};
    int arr2[6] = {-1, 1, 6, 3, 2, 8};
    int n = 5;

    for (int i = n / 2; i >= 1; i--)
        maxheap(arr1, n, i);
    cout << "after maxheap: ";
    for (int i = 1; i <= n; i++)
        cout << arr1[i] << " ";

    incsort(arr1, n);
    cout << "after incsort: "<<endl;
    for (int i = 1; i <= n; i++)
        cout << arr1[i] << " ";

    for (int i = n / 2; i >= 1; i--)
        minheap(arr2, n, i);
    cout << "after minheap: "<<endl;
    for (int i = 1; i <= n; i++)
        cout << arr2[i] << " ";

    decsort(arr2, n);
    cout << "after decsort: "<<endl;
    for (int i = 1; i <= n; i++)
        cout << arr2[i] << " ";

    return 0;
}
