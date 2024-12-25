#include <iostream>
#include <ctime>

using namespace std;

int findMax(int* arr, int n) {
    int max = arr[0];
    for (int i=1; i<n; ++i) {
        if (max < arr[i]) max = arr[i];
    }
    
    return max;
}

int findMin(int* arr, int n) {
    int min = arr[0];
    for (int i=1; i<n; ++i) {
        if (min > arr[i]) min = arr[i];
    }
    
    return min;
}

int calculateSum(int* arr, int n) {
    int sum = 0;
    for (int i=0; i<n; ++i) {
        sum += arr[i];
    }
    
    return sum;
}

double calculateAverage(int* arr, int n) {
    int sum = calculateSum(arr, n);
    
    return (double) sum / n;
}

void fillRandomly(int* arr, int n, bool allUnique) {
    srand(time(0));
    int i = 0;

    while (i < n) {
        int sign = rand() % 3 > 1 ? 1 : -1;
        int candidate = (rand() % n) * sign;

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

const int SIZE = 5;

int main() {
    int arr[SIZE];

    fillRandomly(arr, SIZE, true);
    printArray(arr, SIZE);
    int min = findMin(arr, SIZE);
    int max = findMax(arr, SIZE);
    int sum = calculateSum(arr, SIZE);
    double avg = calculateAverage(arr, SIZE);
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << avg << endl;

    return 0;
}
