#include <iostream>
using namespace std;

class Cars{
    //HAS
    public:
    string brand;
    int speed;
    bool is_ours;
    int newSpeed;
    //DOES
    int accelarate(){
        int acc = speed + 30;
        return acc;
    };
};
class Student{
    public:
    //HAS
    int regNo;
    string name;
    string gender;
    int contact;
    bool isActive;
    //DOES
    void introduce(){
        cout << "My name is "<<name <<" and my Registration number is "<< regNo<< endl;
    }

};
class Dog{
    public:
    void bark(){
        cout <<"Woooof!";
    }
};

int main(){
Cars car1;

car1.speed=122;
cout << "Car1 Speed is: "<< car1.speed << endl;
car1.newSpeed = car1.accelarate();
cout << "Car1 New Speed is: "<< car1.newSpeed<<"m/s2"<<endl;
cout << "Accelarated Successfully" << endl;
Student student1;
student1.name="Lomunyak";
student1.regNo= 215;
student1.introduce();
Dog mydog;
mydog.bark();
return 0;
}