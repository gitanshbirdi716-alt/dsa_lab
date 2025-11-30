#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int freq[256]; 
    for (int i = 0; i < 256; i++) freq[i] = 0;

    char q[1000];  
    int front = 0, rear = -1;  

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ' ') continue;
        q[++rear] = ch;
        freq[ch]++;

        while (front <= rear && freq[q[front]] > 1) {
            front++;
        }

        if (front > rear) cout << -1 << " ";
        else cout << q[front] << " ";
    }
    cout << endl;

    return 0;
}

