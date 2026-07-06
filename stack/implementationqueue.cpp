#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class QueueStack {
public:
    queue<int> q;

    void push(int x) {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    QueueStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;      // 30
    cout << "Pop: " << st.pop() << endl;      // 30
    cout << "Top: " << st.top() << endl;      // 20

    st.push(40);

    cout << "Pop: " << st.pop() << endl;      // 40
    cout << "Pop: " << st.pop() << endl;      // 20
    cout << "Pop: " << st.pop() << endl;      // 10

    cout << "Is Empty: ";
    cout << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}