#include <iostream>
#include <ctime>

using namespace std;

const int LEAST = 1;
const int GREATEST = 100;

int main() {
    srand(time(0));
    
    int secret = LEAST + rand() % (GREATEST - LEAST + 1);
    cout << "Я загадав число від " << LEAST << " до " << GREATEST << ". Спробуй вгадати!" << endl;
    
    int guess;
    int attempts = 0;
    do {
        cout << "Твій варіант: ";
        cin >> guess;
        attempts++;
        
        if (guess < LEAST || guess > GREATEST) {
            cout << "Число має бути: [" << LEAST << "; " << GREATEST << "]" << endl;
            continue;
        }
        
        if (guess < secret) cout << "Більше" << endl;
        if (guess > secret) cout << "Менше" << endl;
    } while (guess != secret);
    
    cout << "Вітаю, число вгадане за " << attempts << " спроб. " << endl;
    
    return 0;
}
