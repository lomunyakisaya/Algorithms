#include <iostream>
using namespace std;

class Fraction{
    public:
    Fraction(int x, int y){
        numerator = x;
        denominator = y;
    }
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
    Rectangle(int x, int y){
       length = x;
       width = y;
    }

    int area(){
        return length * width;
    }
    int perimeter(){
        int sum = width + length;
        return 2 * sum;
    }
};
class Car{
    public:
    int speed;
    int wheels;
    Car(int speed, int wheels){
        speed = speed;
        wheels = wheels
    }
};
int main(){
    Fraction f(23, 16);
    cout <<"Sum is: " << f.add() << endl;
    cout << "Subtraction Value is: "<< f.subtract() <<endl;
    cout << "Difference is: "<<f.difference()<<endl;
    cout << "Product is: " << f.multiply() << endl;
    cout << "Quotient is: " << f.divide() <<endl;
    Rectangle r(56, 47);
    cout << "Perimetor is: "<<r.perimetor()<<endl;
    cout << "Area is: "<<r.area()<<endl;
}