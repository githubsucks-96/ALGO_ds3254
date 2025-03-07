#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int getMin(int a[], int i, int j) {
    int min = i;
    for (int k = i + 1; k <= j; k++) {
        if (a[k] < a[min]) {
            min = k;
        }
    }
    return min;
}

void selsort(int a[], int i) {
    for (int j = 0; j < i; ++j) {
        int min = j;
        int k = getMin(a, j, i);
        if (a[k] < a[j]) {
            int u = a[j];
            a[j] = a[k];
            a[k] = u;
        }
    }
}

void insort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mersort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mersort(arr, left, mid);
        mersort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void measureTime(void (*sortFunc)(int[], int), int arr[], int n, const char* sortName) {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortFunc(arr, n);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(stop - start);

    cout << sortName << " took " << duration.count() << " microseconds for size " << n << "." << endl;
}

void measureTime2(void (*sortFunc)(int[], int, int), int arr[], int left, int right, const char* sortName) {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortFunc(arr, left, right);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    microseconds duration = duration_cast<microseconds>(stop - start);

    cout << sortName << " took " << duration.count() << " microseconds for size " << right - left + 1 << "." << endl;
}

int main() {
    const int sizes[] = {100, 500, 1000, 5000, 10000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int index = 0; index < numSizes; ++index) {
        int size = sizes[index];

        int* arr = new int[size];
        for (int i = 0; i < size; i++) arr[i] = rand() % 10000;

        int* copy = new int[size];
        copy_n(arr, size, copy);
        measureTime(selsort, copy, size, "Selection Sort");

        copy_n(arr, size, copy);
        measureTime(insort, copy, size, "Insertion Sort");

        copy_n(arr, size, copy);
        measureTime2(mersort, copy, 0, size - 1, "Merge Sort");

        delete[] arr;
        delete[] copy;
    }

    return 0;
}


