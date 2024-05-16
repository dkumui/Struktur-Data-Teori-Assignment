#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, x);
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(1);

    cout << "Stack sebelum diurutkan: \n";
    printStack(s);

    sortStack(s);

    cout << "Stack setelah diurutkan: \n";
    printStack(s);

    return 0;
}