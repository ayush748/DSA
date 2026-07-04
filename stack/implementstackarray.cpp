#include <iostream>
using namespace std;
class stack {
public:
    int *arr;
    int cap;
    int top;

    stack(int size = 1000) {
        cap = size;
        arr = new int[cap];
        top = -1;
    }

    ~stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top >= cap - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.Top() << endl;

    cout << "Popped: " << s.pop() << endl;

    cout << "Top element: " << s.Top() << endl;

    cout << "Is Empty: " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}