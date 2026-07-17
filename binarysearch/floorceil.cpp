#include <iostream>
#include <vector>
using namespace std;

pair<int, int> floorCeil(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int floor = -1, ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            floor = ceil = arr[mid];
            return {floor, ceil};
        }
        else if (arr[mid] < x) {
            floor = arr[mid];   // possible floor
            low = mid + 1;
        }
        else {
            ceil = arr[mid];    // possible ceil
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main() {
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int x = 5;

    pair<int, int> ans = floorCeil(arr, x);

    cout << "Floor = " << ans.first << endl;
    cout << "Ceil = " << ans.second << endl;

    return 0;
}