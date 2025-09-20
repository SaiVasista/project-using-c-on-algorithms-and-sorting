#include <iostream>
#include <vector>
#include <algorithm>

// Function to print the array
template<typename T>
void printData(const T& data) {
    for (const auto& element : data) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Merge Function (for Merge Sort)
template<typename T>
void merge(T& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<typename T::value_type> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

// Merge Sort
template<typename T>
void mergeSort(T& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

// Partition (for Quick Sort)
template<typename T>
int partition(T& data, int low, int high) {
    typename T::value_type pivot = data[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

// Quick Sort
template<typename T>
void quickSort(T& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

// Insertion Sort
template<typename T>
void insertionSort(T& data) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        typename T::value_type key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Selection Sort
template<typename T>
void selectionSort(T& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(data[min_idx], data[i]);
    }
}

// Heapify (for Heap Sort)
template<typename T>
void heapify(T& data, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;
    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

// Heap Sort
template<typename T>
void heapSort(T& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

// Bubble Sort
template<typename T>
void bubbleSort(T& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

// Main Program
int main() {
    int n, choice;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "\nChoose Sorting Algorithm:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Merge Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Heap Sort\n";
    std::cout << "Enter choice (1-6): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            std::cout << "Sorted with Bubble Sort: ";
            break;
        case 2:
            selectionSort(arr);
            std::cout << "Sorted with Selection Sort: ";
            break;
        case 3:
            insertionSort(arr);
            std::cout << "Sorted with Insertion Sort: ";
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            std::cout << "Sorted with Merge Sort: ";
            break;
        case 5:
            quickSort(arr, 0, n - 1);
            std::cout << "Sorted with Quick Sort: ";
            break;
        case 6:
            heapSort(arr);
            std::cout << "Sorted with Heap Sort: ";
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return 0;
    }

    printData(arr);

    return 0;
}
