#include <iostream>
#include <iomanip> // для std::setprecision

using namespace std;

double min(const double a, const double b) {
    return a < b ? a : b;
}

double max(const double a, const double b) {
    return a > b ? a : b;
}

double calculateCost(const double kWh) {
    double part1 = min(kWh, 100);
    double part2 = min(max(kWh - 100, 0.0), 100.0);
    double part3 = max(kWh - 200, 0.0);
    
    return part1 * 1.5 + part2 * 2.0 + part3 * 3.0;
}

double applyTax(const double cost) {
    return cost * 1.05;
}

int main() {
    double kWh;
    cout << "Введіть витрачені кв*год: ";
    cin >> kWh;
    if (kWh < 0.0) {
        cout << "Значення має бути додатнім!" << endl;
        return 0;
    }
    
    double baseCost = calculateCost(kWh);
    double tax = kWh > 300.0 ? applyTax(baseCost) : 0.0;
    double totalCost = baseCost + tax;
    
    cout << fixed << setprecision(2); // друкувати 2 знаки після коми
    cout << "Загальна вартість: " << totalCost << " грн." << endl;

    return 0;
}
