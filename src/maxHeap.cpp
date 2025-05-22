#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Root index
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is bigger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is bigger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not the largest
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Max-Heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);           // Move root to the end
        maxHeapify(arr, i, 0);          // Heapify the remaining elements
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "Before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "After heap sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
