#include <stdio.h>
 int array[5] = {45, 56, 34, 34, 56};
int main(){
 for (int i =0; i <=4; i++){
    printf("%p\n", &array[i]);
 }
 return 0;
}