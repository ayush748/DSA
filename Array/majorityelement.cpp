#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    int cnt1 = 0, cnt2 = 0;
    int maj1 = 0, maj2 = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == maj1) {
            cnt1++;
        }
        else if (nums[i] == maj2) {
            cnt2++;
        }
        else if (cnt1 == 0) {
            maj1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            maj2 = nums[i];
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int x : nums) {
        if (x == maj1)
            cnt1++;
        else if (x == maj2)
            cnt2++;
    }

    vector<int> ans;

    if (cnt1 > n / 3)
        ans.push_back(maj1);
    if (cnt2 > n / 3)
        ans.push_back(maj2);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = majorityElement(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}