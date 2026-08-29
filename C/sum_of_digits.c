#include <stdio.h>
int number = 12345;
int sum;
int digit;
int main(){
  while(number > 0){
    digit = number % 10;
    sum = sum + digit;
    number = number / 10;
  }
  printf("The Sum of Numbers You Gave is: %d\n", sum);
}