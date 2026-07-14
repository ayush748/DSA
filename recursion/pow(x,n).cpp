#include <iostream>
using namespace std;

double solve(double x, long long n) {
    if (n == 0) {
        return 1;
    }

    double h = solve(x, n / 2);

    if (n % 2 == 0) {
        return h * h;
    } else {
        return h * h * x;
    }
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    long long val = n;

    if (val < 0) {
        x = 1.0 / x;
        val = -val;
    }

    double ans = solve(x, val);
    cout << ans;

    return 0;
}