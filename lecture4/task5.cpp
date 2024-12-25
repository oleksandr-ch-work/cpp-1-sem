#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void rowSums(int arr[ROWS][COLS]) {
    for (int i=0; i<ROWS; ++i) {
        int sum = 0;
        for (int j=0; j<COLS; ++j)
            sum += arr[i][j];
        
        cout << "Сума елементів строки №" << i + 1 << ": " << sum << endl;
    }
}

void fillRandomly(int* arr, int n, bool allUnique, int max) {
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

void printMatrix(int arr[ROWS][COLS]) {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j)
            cout << arr[i][j] << " ";
        
        cout << endl;
    }
}

void fillMatrix(int arr[ROWS][COLS]) {
    for (int i=0; i<ROWS; ++i) {
        fillRandomly(arr[i], COLS, false, COLS * COLS);
    }
}

int main() {
    srand(time(0));
    int matrix[ROWS][COLS] = {};
    
    fillMatrix(matrix);
    printMatrix(matrix);

    rowSums(matrix);

    return 0;
}
