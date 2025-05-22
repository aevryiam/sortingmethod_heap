#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build the Min-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    // Display results after Min-Heap Sort (descending)
    cout << "After heap sort (Min-Heap, descending): ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Reverse to get the final result in ascending order
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "Before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    // Display the final result in ascending order
    cout << "After reverse (ascending final result): ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
