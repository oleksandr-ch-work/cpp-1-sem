#include <iostream>
#include <ctime>

using namespace std;

void analyze(int* arr, int n) {
    int sum = arr[0];
    int min = arr[0];
    int max = arr[0];
    
    for (int i=1; i<n; ++i) {
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
        sum += arr[i];
    }
    
    double avg = (double) sum / n;
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << sum << endl;
    cout << "Avg: " << avg << endl;
}

void fillRandomly(int* arr, int n, bool allUnique) {
    srand(time(0));
    int i = 0;
    
    while (i < n) {
        int sign = rand() % 3 == 0 ? 1 : -1;
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

const int SIZE = 3;

int main() {
    int arr[SIZE];
    
    fillRandomly(arr, SIZE, true);
    printArray(arr, SIZE);
    analyze(arr, SIZE);

    return 0;
}
