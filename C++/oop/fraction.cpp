#include <iostream>
using namespace std;

class Fraction{
    public:
    int numerator;
    int denominator;

    float divide(){
        numerator = numerator;
        denominator = denominator;
        return (float)numerator/denominator;
     }
 
     int multiply(){
        return numerator * denominator;
     }
     int add(){
        return numerator + denominator;
     }
     int difference(){
        int large = (numerator >= denominator) ? numerator : denominator;
        int small = (denominator >= numerator) ? numerator : denominator;
        return large - small;
     }
     int subtract(){
        return numerator - denominator;
     }
};
class Rectangle{
    public:
    int width;
    int length;

    int area(){
        return length * width;
    }
    int perimetor(){
        int sum = width + length;
        return 2 * sum;
    }
};
int main(){
    Fraction f;
    f.numerator = 12;
    f.denominator =17;
    cout <<"Sum is: " << f.add() << endl;
    cout << "Subtraction Value is: "<< f.subtract() <<endl;
    cout << "Difference is: "<<f.difference()<<endl;
    cout << "Product is: " << f.multiply() << endl;
    cout << "Quotient is: " << f.divide() <<endl;
    Rectangle r;
    r.length = 12;
    r.width = 7;
    cout << "Perimetor is: "<<r.perimetor()<<endl;
    cout << "Area is: "<<r.area()<<endl;
    
}