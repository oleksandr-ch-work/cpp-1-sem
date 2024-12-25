#include <iostream>

using namespace std;

bool isLeapYear(const int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool isValidDate(int day, int month, bool isLeapYear) {
    int daysInMonth[] = {31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth[month - 1]) return false;
    
    return true;
}

int main() {
    int day, month, year;
    cout << "Введіть день, місяць та рік: ";
    cin >> day >> month >> year;
    
    if (day <= 0 || month <= 0 || year <= 0) {
        cout << "День, місяц та рік мають бути додатні!" << endl;
        return 0;
    }
    
    bool leap = isLeapYear(year);
    bool dateIsValid = isValidDate(day, month, leap);
    
    cout << day << "." << month << "." << year << " -> " << (dateIsValid ? "ОК" : "не існує") << endl;
    
    return 0;
}
