#include "calculator.h"
#include <iostream>

using namespace std;

int main()
{
    calculator myCalc;

    cout << "Add: " << myCalc.add(10, 5) << endl;
    cout << "Subtract: " << myCalc.subtract(10, 5) << endl;
    cout << "Multiply: " << myCalc.multiply(10, 5) << endl;
    cout << "Divide: " << myCalc.divide(10, 5) << endl;

    return 0;
}