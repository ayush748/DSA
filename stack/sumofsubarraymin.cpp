#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef unsigned long long ll;

vector<int> getNSL(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            result[i] = -1;
        } else {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }

    return result;
}

vector<int> getNSR(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            result[i] = n;
        } else {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }

    return result;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();

    vector<int> NSL = getNSL(arr, n);
    vector<int> NSR = getNSR(arr, n);

    ll sum = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        ll left = i - NSL[i];
        ll right = NSR[i] - i;

        ll ways = left * right;
        ll contribution = (1LL * arr[i] * ways) % mod;

        sum = (sum + contribution) % mod;
    }

    return sum;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};

    cout << sumSubarrayMins(arr) << endl;

    return 0;
}