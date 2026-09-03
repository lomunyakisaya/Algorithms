#include <iostream>
using namespace std;

int main(){
    int x = 56;
    int y = 84;
    int z = 9123;
    int large = x;
    if (large > y && large < z){
        cout << y << "(y) is Greatest";
    }
    else if (large < y && large > z){
        cout << z <<"(z) is Greatest";
    }
    else{
        cout << x << "(x) is Greatest";
    }


}