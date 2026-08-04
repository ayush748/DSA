#include <iostream>
using namespace std;

const int MAX = 100;

// Traversal
void traverse(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Insertion
void insertElement(int arr[], int &n, int pos, int value) {
    if (pos < 0 || pos > n) {
        cout << "Invalid Position\n";
        return;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;
}

// Deletion
void deleteElement(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid Position\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

// Updating
void updateElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid Position\n";
        return;
    }

    arr[pos] = value;
}

int main() {
    int arr[MAX] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Original ";
    traverse(arr, n);

    // Insertion
    insertElement(arr, n, 2, 25);
    cout << "After Insertion ";
    traverse(arr, n);

    // Deletion
    deleteElement(arr, n, 4);
    cout << "After Deletion ";
    traverse(arr, n);

    // Updating
    updateElement(arr, n, 1, 100);
    cout << "After Updating ";
    traverse(arr, n);

    return 0;
}