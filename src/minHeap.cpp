#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std;
using namespace std::chrono;

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
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    reverse(arr.begin(), arr.end());
}

vector<int> loadFromCSV(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    string line;

    if (getline(file, line)) {
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            try {
                data.push_back(stoi(value));
            } catch (...) {
                cerr << "Invalid value in CSV: " << value << endl;
            }
        }
    }
    return data;
}

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        cout << "Memory used: " << memInfo.WorkingSetSize / 1024 << " KB" << endl;
    } else {
        cerr << "Failed to get memory usage." << endl;
    }
}

int main() {
    string filename = "input.csv";
    vector<int> arr = loadFromCSV(filename);

    if (arr.empty()) {
        cout << "File is empty or unreadable. Using default data.\n";
        arr = {4, 10, 3, 5, 1};
    }

    cout << "Before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto stop = high_resolution_clock::now();

    cout << "After heap sort (ascending): ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    printMemoryUsage();

    return 0;
}
