#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// =====================================================
// 1. BRUTE FORCE APPROACH - O(n^3)
// =====================================================

int bruteForce(string s) {

    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {

            unordered_set<char> st;
            bool valid = true;

            for (int k = i; k <= j; k++) {

                if (st.count(s[k])) {
                    valid = false;
                    break;
                }

                st.insert(s[k]);
            }

            if (valid) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}


// =====================================================
// 2. BETTER APPROACH - O(n^2)
// =====================================================

int betterApproach(string s) {

    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        unordered_set<char> st;

        for (int j = i; j < n; j++) {

            // Duplicate found
            if (st.count(s[j])) {
                break;
            }

            st.insert(s[j]);

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}


// =====================================================
// 3. SLIDING WINDOW - O(n)
// =====================================================

int slidingWindow(string s) {

    int left = 0;
    int right = 0;
    int maxLen = 0;

    unordered_set<char> st;

    while (right < s.length()) {

        // Character is not repeated
        if (!st.count(s[right])) {

            st.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        // Duplicate character
        else {

            st.erase(s[left]);

            left++;
        }
    }

    return maxLen;
}


// =====================================================
// 4. OPTIMAL - SLIDING WINDOW + LAST INDEX - O(n)
// =====================================================

int optimalApproach(string s) {

    unordered_map<char, int> lastIndex;

    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++) {

        char ch = s[right];

        // If character was already seen
        // and is inside current window
        if (lastIndex.count(ch) &&
            lastIndex[ch] >= left) {

            left = lastIndex[ch] + 1;
        }

        // Store latest index
        lastIndex[ch] = right;

        // Current window length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}


// =====================================================
// MAIN FUNCTION
// =====================================================

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "\nBrute Force: "
         << bruteForce(s) << endl;

    cout << "Better Approach: "
         << betterApproach(s) << endl;

    cout << "Sliding Window: "
         << slidingWindow(s) << endl;

    cout << "Optimal Approach: "
         << optimalApproach(s) << endl;

    return 0;
}