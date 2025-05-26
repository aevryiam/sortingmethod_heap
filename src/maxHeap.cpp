#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

vector<int> loadFromCSV(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    string line;

    if (getline(file, line)) {
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            data.push_back(stoi(value));
        }
    }
    return data;
}

size_t getMemoryUsedKB() {
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        return memInfo.WorkingSetSize / 1024;
    } else {
        return 0;
    }
}

int main() {
    string filename = "input.csv";
    vector<int> arr = loadFromCSV(filename);

    if (arr.empty()) {
        cout << "File is empty or cannot be read. Using default data." << endl;
        arr = {4, 10, 3, 5, 1};
    }

    // Before sorting output
    // cout << "Before sorting: ";
    // for (int num : arr)
    // cout << num << " ";
    // cout << endl;

    size_t inputSize = arr.size();

    // Sorting & timing
    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    size_t memoryKB = getMemoryUsedKB();

    // Output results (all elements)
    // cout << "After heap sort: ";
    // for (int num : arr)
    //     cout << num << " ";
    // cout << endl;


    // Output first 10 elements only
    cout << "Sorted (first 10): ";
    for (int i = 0; i < min((size_t)10, arr.size()); i++)
        cout << arr[i] << " ";
    cout << "...\n";

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    cout << "Memory used: " << memoryKB << " KB" << endl;

    return 0;
}
