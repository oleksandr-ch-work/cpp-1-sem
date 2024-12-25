#include <iostream>
#include <iomanip> // для std::setprecision

using namespace std;

const double MAX_HEIGHT = 2.5;
const double MAX_WEIGHT = 250;

string getBMIDescription(const double bmi) {
    if (bmi < 16) return "дефіцит";
    if (bmi < 16.9) return "помірний дефіцит";
    if (bmi < 18.4) return "легкий дефіцит";
    if (bmi < 24.9) return "норма";
    if (bmi < 29.9) return "надмірна маса";
    if (bmi < 34.9) return "ожиріння I ступеня";
    if (bmi < 39.9) return "ожиріння II ступеня";
    
    return "ожиріння III ступеня";
}

int main() {
    double height;
    cout << "Введіть зріст в метрах: ";
    cin >> height;
    
    if (height <= 0 || height > MAX_HEIGHT) {
        cout << "Зріст має бути додатнім та не більше " << MAX_HEIGHT <<" м." << endl;
        return 0;
    }
    
    cout << "Введіть масу в кг: ";
    double weight;
    cin >> weight;
    
    if (weight <= 0 || weight > MAX_WEIGHT) {
        cout << "Маса має бути додатньою та не більше " << MAX_WEIGHT <<" кг." << endl;
        return 0;
    }
    
    const double bmi = weight / (height * height);
    
    cout << fixed << setprecision(2); // друкувати 2 знаки після коми
    cout << "Індекс маси тіла: " << bmi << " -> (" << getBMIDescription(bmi) << ")" << endl;
    
    return 0;
}
