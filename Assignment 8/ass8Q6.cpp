#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;   
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int top() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }
    void pop() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    bool empty() {
        return heap.size() == 0;
    
    void display() {
        cout << "Heap: ";
        for (int x : heap) {
            cout << x << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap pq;
    pq.push(40);
    pq.push(20);
    pq.push(60);
    pq.push(10);
    pq.push(50);
    pq.display();                      
    cout << "Max = " << pq.top() << endl;
    pq.pop();
    cout << "After deleting max:" << endl;
    pq.display();

    return 0;
}

