#include <iostream>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 1, b = 2;
    mySwap(a, b);
    cout << a << " " << b;
    
    return 0;
}
