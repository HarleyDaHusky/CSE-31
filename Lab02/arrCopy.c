#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

// DO NOT change the definition of the printArr function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void printArr(int *a, int size, char *prompt){
    printf("%s", prompt);
    if(size > 0){  
        for(int i = 0; i < size; i++){
            printf("%d ", a[i]);
        }
    }
    else{
        printf("empty");
    }
    printf("\n");
}

// DO NOT change the definition of the arrCopy function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void arrCopy(){
    int evenCounter = 0;
    int oddCounter = 0;
     for(int i = 0; i < size; i++){
        //printf("%d\n", (*(arr+i)));
        //printf("%p\n", arr);
        if(*(arr+i) %2==0){
            int *point = arr_even+evenCounter;
            *point = *(arr+i);
            evenCounter++;
        }
        else{
            int *point = arr_odd+oddCounter;
            *point = *(arr+i);
            oddCounter++;
        }
     }
}

int main(){
    int input;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    // Dynamically allocate memory for arr (of appropriate size)
    arr = (int*) malloc(sizeof((int)size));

    // Ask user to input content of arr and compute evenCount and oddCount
    for(int i = 0; i < size; i++){
        printf("Enter array element #%d: ", i+1);
        scanf("%d", &input);
        if(input%2 == 0){
            evenCount++;
        }
        else{
            oddCount++;
        }
        arr[i] = input;
    }

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    arr_even = (int*) malloc(sizeof((int)evenCount));
    arr_odd = (int*) malloc(sizeof((int)oddCount));
    printf("\n");
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}