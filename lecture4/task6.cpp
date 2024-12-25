#include <iostream>

using namespace std;

void printArray(int* arr, int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findIndex(int* arr, int n, int value) {
    for (int i = 0; i<n; ++i) {
        if (arr[i] == value) return i;
    }
    
    return -1;
}

bool exists(int* arr, int n, int value) {
    return findIndex(arr, n, value) != -1;
}

bool insert(int* arr, int n, int value, int pos) {
    if (pos > n || pos < 0) return false;
    
    for (int i = n-1; i>=pos; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[pos] = value;
    
    return true;
}

bool remove(int* arr, int n, int value) {
    if (n < 1) return false;
    
    int pos = findIndex(arr, n, value);
    if (pos == -1) return false;
    
    for (int i = pos; i<n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    
    return true;
}

int replaceAll(int* arr, int n, int old, int target) {
    int replaced = 0;
    
    for (int i=0; i<n; ++i) {
        if (arr[i] == old) {
            arr[i] = target;
            replaced++;
        }
    }
    
    return replaced;
}

void testFindIndex() {
    const int n = 4;
    int arr[n] = {1, 4, 5, 6};
    
    cout << "index(1): " << findIndex(arr, n, 1) << endl;
    cout << "index(4): " << findIndex(arr, n, 4) << endl;
    cout << "index(6): " << findIndex(arr, n, 6) << endl;
    cout << "index(77): " << findIndex(arr, n, 77) << endl;
}

void testExists() {
    const int n = 4;
    int arr[n] = {1, 4, 5, 6};
    
    cout << "exists(1): " << exists(arr, n, 1) << endl;
    cout << "exists(4): " << exists(arr, n, 4) << endl;
    cout << "exists(6): " << exists(arr, n, 6) << endl;
    cout << "exists(77): " << exists(arr, n, 77) << endl;
}

void testReplaceAll() {
    const int n = 5;
    int arr[n] = {1, 1, 4, 5, 6};
    
    cout << "replace(1, -1): " << replaceAll(arr, n, 1, -1) << endl;
    cout << "replace(6, 7): " << replaceAll(arr, n, 6, 7) << endl;
    cout << "replace(0, 444): " << replaceAll(arr, n, 0, 444) << endl;
}

void testInsert() {
    const int capacity = 10;
    int n = 5;
    
    int arr[capacity] = {1, 2, 3, 4, 5};
    
    cout << "insert(1, 0): " << insert(arr, n, 77, 0) << endl;
    n++;
    printArray(arr, n);
    cout << "insert(66, n): " << insert(arr, n, 66, n) << endl;
    n++;
    printArray(arr, n);
    cout << "insert(55, 2): " << insert(arr, n, 55, 2) << endl;
    n++;
    printArray(arr, n);
}

void testRemove() {
    const int capacity = 5;
    int n = 5;
    int arr[capacity] = {1, 2, 3, 4, 5};
    
    cout << "remove(1): " << remove(arr, n, 1) << endl;
    n--;
    printArray(arr, n);
    cout << "remove(5): " << remove(arr, n, 5) << endl;
    n--;
    printArray(arr, n);
    cout << "remove(3): " << remove(arr, n, 3) << endl;
    n--;
    printArray(arr, n);
}

int main() {
    testFindIndex();
    testExists();
    testReplaceAll();
    testInsert();
    testRemove();
}
