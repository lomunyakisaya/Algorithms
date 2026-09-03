#include<stdio.h>

int main(){
    int x;
    int y;
    int z;
    printf("Enter Three Numbers: ");
    scanf("%d%d%d", &x, &y, &z);
    
    if (x > y & x > z){
        printf("X is the Grea\test");
    }
    else if(y > x & y > z)
    {
        printf("Y is Greatest");
    }
    else{
        printf("Z is Greatest");
    }
    return 0;
}