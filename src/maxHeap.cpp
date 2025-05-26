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

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        cout << "Memory used: " << memInfo.WorkingSetSize / 1024 << " KB" << endl;
    } else {
        cerr << "Failed to get memory usage." << endl;
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

int main() {
    string filename = "input.csv";
    vector<int> arr = loadFromCSV(filename);

    if (arr.empty()) {
        cout << "File is empty or cannot be read. Using default data." << endl;
        arr = {4, 10, 3, 5, 1};
    }

    cout << "Before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto stop = high_resolution_clock::now();

    cout << "After heap sort: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    printMemoryUsage();
    
    return 0;
}
