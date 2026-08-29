#include <stdio.h>
 //n is number of elements in the array
 //i is the number of passes
 //j is the number of comparisons in each pass
void sort(int arr[], int n){
    //passing 
    //this loop contrals number of passes
    for (int i = 0; i < n - 1; i++){
        //then loop to compare
        for(int j =0; j < n - i; j++){
            //Now Compare two neighbouring elements
            //if left element is larger swap them
            if (arr[j] > arr[j+1]){

                //store it temporarily
                int temp = arr[j];
                
                //move the smaller value to left
                arr[j] = arr[j + 1];
                //put larger to the right
                arr[j + 1] + temp;
            }
        }
    }
        
        
}
//now my main function
int main(){
    int numbers[] = {76, 56, 89, 94, 78, 89, 90};
    //calculate the number of elements in the array
    int n = sizeof(numbers) / sizeof(numbers[0]);
    // Display the original array
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    // Sort the array
    sort(numbers, n);
    // Display the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}