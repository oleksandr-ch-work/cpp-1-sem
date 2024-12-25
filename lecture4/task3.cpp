#include <iostream>
#include <ctime>

using namespace std;

void detectAnomalies(int temperatures[], int size, int minTemp, int maxTemp) {
    for (int i=0; i<size; ++i) {
        if (temperatures[i] < minTemp || temperatures[i] > maxTemp)
            cout << "Аномальний показник №" << i + 1 << ": " << temperatures[i] << endl;
    }
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

const int SIZE = 10;

int main() {
    int arr[SIZE];

    fillRandomly(arr, SIZE, true, 50);
    printArray(arr, SIZE);
    
    int minTemp = -20;
    int maxTemp = 35;
    detectAnomalies(arr, SIZE, minTemp, maxTemp);

    return 0;
}
