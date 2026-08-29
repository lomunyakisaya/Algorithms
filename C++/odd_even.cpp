#include <iostream>
using namespace std;

int main(){
    int x = 0;
    if (x == 0){
        cout << "Number Is Zero";
    }
    else if(x > 0){
        cout << "Positive Number"; 
    }
    else if(x < 0){
        cout <<"Negative Number";
    }
    else{
        cout << "Invalid Option";
    }
    return 0;
}