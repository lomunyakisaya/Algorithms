#include <iostream>
using namespace std;
int myArray[10] = {12, 6, 43, 100, 0, 46, 51, 20, 89, 21};
int sortedArray[10];
int main(){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j < i-1; j++){
            if(myArray[j] > myArray[j+1]){
                int temp = myArray[j];
                myArray[j] = myArray[j + 1];
                myArray[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array is:\n";
    for (int n = 0; n < 9; n++){
        cout <<myArray[n] << " ";
    }
cout << "\nProgram Finished With Exit Code O";
return 0;
}