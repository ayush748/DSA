#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
            return;
        }

        int mini = min(getMin(), value);
        st.push({value, mini});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << s.getMin() << " ";

    s.pop();
    cout << s.top() << " ";

    s.pop();
    cout << s.getMin();

    return 0;
}