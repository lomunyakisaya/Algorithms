//Day 1
#include <stdio.h>
int reverse_number;
int digit;
int num;
int main(){
    int num = 89767362;
    while(num > 0){
    digit = num % 10;
    reverse_number = reverse_number * 10 + digit;
    num = num / 10;
    }
printf("Reversed Number Is %d", reverse_number);
}
