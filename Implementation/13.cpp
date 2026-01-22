#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int cnt = 0;

    // Count lucky digits
    while (n > 0) {
        int val = n % 10;
        if (val == 4 || val == 7)
            cnt++;
        n /= 10;
    }

    if (cnt == 0) {
        cout << "NO";
        return 0;
    }

    // Check if count is lucky
    while (cnt > 0) {
        int val = cnt % 10;
        if (val != 4 && val != 7) {
            cout << "NO";
            return 0;
        }
        cnt /= 10;
    }

    cout << "YES";
    return 0;
}
