#include <iostream>

using namespace std;

int main() {
    int a = 17, b = 536;
    
    // swap
    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << a << " " << b << endl;
    
    return 0;
}
