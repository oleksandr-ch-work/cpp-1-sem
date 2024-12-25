#include <iostream>
using namespace std;

const int HELLO_COMMAND = 1;
const int YEAR_COMMAND = 2;
const int EXIT_COMMAND = 3;

void showMenu() {
    cout << HELLO_COMMAND << ". Сказати \"Hello, World\"" << endl;
    cout << YEAR_COMMAND << ". Показати поточний рік" << endl;
    cout << EXIT_COMMAND << ". Вихід" << endl;
}

void sayHello() {
    cout << "Hello, world" << endl;
}

void showCurrentYear() {
    cout << "Поточний рік: 2024" << endl;
}

void sayGoodbye() {
    cout << "Завершення роботи..." << endl;
}

int main() {
    do {
        showMenu();
        
        int command;
        cout << "Введіть команду: ";
        cin >> command;
        
        switch (command) {
            case HELLO_COMMAND: {
                sayHello();
                break;
            }
                
            case YEAR_COMMAND: {
                showCurrentYear();
                break;
            }
                
            case EXIT_COMMAND: {
                sayGoodbye();
                return 0;
            }
                
            default: {
                cout << "Команда " << command << " недоступна" << endl;
                break;
            }
        }
    } while (true);
    
    return 0;
}
