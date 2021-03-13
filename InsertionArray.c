#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Insertion sort */
void insertion_sort(int arr[], int n){

    int current, i, j;

    //Start iteration from the second element in the array
    for(i = 1; i < n; i++){

        //Store the current element
        current = arr[i];
        j = i - 1;

        // j has to be greater than equal 0
        // the current element has to be less than its predecessor for it to move
        while(j >= 0 && current <= arr[j]){

            //Change the location of the predecessor
            arr[j+1] = arr[j];

            //Check the element before the immediate predecessor
            j = j-1;

        }

        //Once the right location is found set it equal to the current element
        //Note at the end of while j = j-1
        //here j+1 = j-1 + 1 = j
        arr[j+1] = current;

    }

}

int main(){

    int A[] = {1, 11, 12, 300, 12, 20, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
 
    printf("The original array:\n");
    printArray(A,n);

    printf("\nNow the array is sorted (in place):\n");

    insertion_sort(A, n);
    printArray(A, n);
 
    return 0;
}





