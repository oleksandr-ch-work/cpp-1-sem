#include <iostream>
#include <ctime>

using namespace std;

int findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int total = 0;
    
    for (int i = 0; i<size1; ++i) {
        for (int j=0; j<size2; ++j) {
            if (arr1[i] == arr2[j]) {
                total++;
                break;
            }
        }
    }
    
    return total;
}

void fillRandomly(int* arr, int n, bool allUnique, int max) {
    srand(time(0));
    int i = 0;

    while (i < n) {
        int sign = rand() % 3 > 1 ? 1 : -1;
        int candidate = (rand() % max + 1) * sign;

        bool duplicateFound = false;

        if (allUnique && i > 0) {
            for (int j = i-1; j>=0; j--) {
                if (candidate == arr[j]) {
                    duplicateFound = true;
                    break;
                }
            }
        }

        if (!duplicateFound) {
            arr[i++] = candidate;
        }
    }
}

void printArray(int* arr, int n) {
    cout << "Масив: ";
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

const int SIZE1 = 5;
const int SIZE2 = 3;

int main() {
    int arr1[SIZE1];
    int arr2[SIZE2];

    fillRandomly(arr1, SIZE1, true, SIZE1);
    fillRandomly(arr2, SIZE2, true, SIZE2);
    
    printArray(arr1, SIZE1);
    printArray(arr2, SIZE2);
 
    int commonCount = findIntersection(arr1, SIZE1, arr2, SIZE2);
    
    cout << "Спільних елементів: " << commonCount << endl;

    return 0;
}
