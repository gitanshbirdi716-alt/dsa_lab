#include <iostream>
using namespace std;

struct Queue {
    int arr[1000];
    int front, rear;
    Queue() { front = 0; rear = -1; }
    bool isEmpty() { return front > rear; }
    void push(int x) { arr[++rear] = x; }
    int pop() { return arr[front++]; }
    int peek() { return arr[front]; }
    int size() { return rear - front + 1; }
};

struct Stack {
    Queue q1, q2;

    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.pop());
        }
        cout << "Popped: " << q1.pop() << endl;
       
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.pop());
        }
        int t = q1.pop();
        cout << "Top: " << t << endl;
        q2.push(t);

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.top();  
    st.pop();  
    st.top();  

    return 0;
}

