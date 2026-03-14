#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Next Greater Element to Left
vector<int> NGEL(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;   // store values

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}

// Next Greater Element to Right
vector<int> NGER(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}

// Next Smaller Element to Left
vector<int> NSEL(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}

// Next Smaller Element to Right
vector<int> NSER(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}

int main() {
    vector<int> a = {4, 5, 2, 10, 8};

    vector<int> ngel = NGEL(a);
    vector<int> nger = NGER(a);
    vector<int> nsel = NSEL(a);
    vector<int> nser = NSER(a);

    cout << "NGEL: ";
    for (auto x : ngel) cout << x << " ";
    cout << "\n";

    cout << "NGER: ";
    for (auto x : nger) cout << x << " ";
    cout << "\n";

    cout << "NSEL: ";
    for (auto x : nsel) cout << x << " ";
    cout << "\n";

    cout << "NSER: ";
    for (auto x : nser) cout << x << " ";
    cout << "\n";

    return 0;
}