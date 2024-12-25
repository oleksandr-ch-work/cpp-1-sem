#include <iostream>

using namespace std;

int max(const int a, const int b) {
    return a > b ? a : b;
}

int min(const int a, const int b) {
    return a < b ? a : b;
}

int abs(const int v) {
    return v >= 0 ? v : -v;
}

int signum(const int v) {
    if (v > 0) return 1;
    if (v == 0) return 0;
    
    return -1;
}

int main() {
    const int a = 42;
    const int b = -4;
    const int c = 0;
    
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    
    cout << "min: " << min(a, b) << endl;
    cout << "max: " << max(a, b) << endl;
    
    cout << "abs(a): " << abs(a) << endl;
    cout << "abs(b): " << abs(b) << endl;
    cout << "abs(c): " << abs(c) << endl;
    
    cout << "signum(a): " << signum(a) << endl;
    cout << "signum(b): " << signum(b) << endl;
    cout << "signum(c): " << signum(c) << endl;
    
    return 0;
}
