#include <iostream>
using namespace std;

class queue {
public:
    int *arr;
    int cap;
    int front;
    int rear;

    queue(int size = 1000) {
        cap = size;
        arr = new int[cap];
        front = 0;
        rear = -1;
    }

    ~queue() {
        delete[] arr;
    }

    void push(int x) {
        if (rear >= cap - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front++];
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};

int main() {
    queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.Front() << endl;

    cout << "Popped: " << q.pop() << endl;

    cout << "Front element: " << q.Front() << endl;

    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}