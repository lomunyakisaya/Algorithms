#include<stdio.h>

int main(){
    int x;
    int y;
    printf("Enter Two Numbers x: \n");
    scanf("%d%d", &x, &y);
    if(x > y){
        printf("x is greater than y");
    }
    else{
        printf("y is greater than x");
    }
return 0;
}