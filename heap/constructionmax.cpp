#include <iostream>
using namespace std;

class Heap {

public:

    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1) {

            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void deleteRoot() {

        if(size == 0)
            return;

        arr[1] = arr[size];
        size--;

        int i = 1;

        while(i <= size) {

            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if(left <= size && arr[left] > arr[largest])
                largest = left;

            if(right <= size && arr[right] > arr[largest])
                largest = right;

            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
                break;
        }
    }

    void print() {

        for(int i = 1; i <= size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[largest])
        largest = left;

    if(right <= n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {

    for(int i = n/2; i >= 1; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {

    while(n > 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main() {

    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "After Insertion:\n";
    h.print();

    h.deleteRoot();

    cout << "After Deletion:\n";
    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    buildHeap(arr, n);

    cout << "Built Heap:\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << "\n";

    heapSort(arr, n);

    cout << "Heap Sort:\n";
    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}