#include <iostream>

using namespace std;

int main() {
    long n;
    cout << "До якого числа рахувати квадрат: ";
    cin >> n;
    if (n < 0) {
        cout << "Число має бути додатнім" << endl;
        return 0;
    }
    
    for (int i = 1; i<=n; ++i) {
        cout << i << "^2 = " << i*i << endl;
    }
    
    return 0;
}
