#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
bool found = false;
// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            printf("%c ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

//Char between 96 and 123 are lowercase, -32 to make upper case
void upper(char* word){
    for(int i = 0; i < strlen(word); i++){
        if(*(word+i) > 96 && *(word+i) < 123){
            *(word+i) = *(word+i)-32;
        }
    }
}

bool nearby(char** arr, int i, int j, int index, char* word, int** foundArr)
{
    //checks if nearby index contains char
    //if the index is the same size as the length of the word, return true and stop
    if(index == strlen(word)){
        return true;
    }
    //else, increment slowly, k=i-1 is 1 left of the index and i+1 is right 1 of the index,
    //this makes sense as we are only looking for characters 1 index away surrounding previous char
    for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
            //k and l (i,j) cannot be less than 0 index,
            //k and l cannot be an index larger than size,
            //k and l should be equal to i and j respectfully
            if(k < 0 || l < 0 || k >= bSize || l>= bSize || (k==i && l==j)){
                continue;
            }
            //if the character at k,l is the char we're looking for
            if((*(*(arr+k)+l)) == *(word+index)){
                index++;
                //recursively call nearby to keep checking next characters
                if(nearby(arr,k,l,index,word,foundArr)==true){
                    //when recursion ends, all characters/indexes will be saved
                    if(*(*(foundArr + k) + l) == 0){
                        *(*(foundArr + k) + l) = index;
                    }
    
                    else if(*(*(foundArr + k) + l) > 0){
                        *(*(foundArr + k) + l) = *(*(foundArr + k) + l) * 10 + index;    
                    }
                    //return true so found = true;
                    return true;
                }
                else{
                    //Go back a letter to see for alternate options
                    index--;
                }
            }
        }
    }
    //if Index is backed out all the way, returns false and thus path failed
    return false;
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the word appears in arr, it will print out a message and the path as shown in 
    // the sample runs. If not found, it will print a different message as shown in the sample runs.
    // Your implementation here...

    upper(word);
    int index = 0;
    //if path is true there is at least 1 path available
    bool path = false;
    //Final is a local 2D array that maps out the pathways
    int **foundArr = (int**)malloc(bSize * sizeof(int*));

    for(int i = 0; i < bSize; i++){
        *(foundArr + i) = (int*)malloc(bSize * sizeof(int));
        for(int j = 0; j < bSize; j++){
            *(*(foundArr + i) + j) = 0;
        }
    }

    for(int i = 0; i < bSize; i++){
        for(int j = 0; j < bSize; j++){
            if(*(*(arr + i) + j) == *(word)){ 
                index++;
                found = nearby(arr, i, j, index, word, foundArr);
                if(found){
                    if(*(*(foundArr + i) + j) == 0){
                        *(*(foundArr + i) + j) = index;
                    }
    
                    else if(*(*(foundArr + i) + j) > 0){
                        *(*(foundArr + i) + j) = *(*(foundArr + i) + j) * 10 + index;    
                    }    
                    path = found;
                }
                index = 0;
            }
        }
    }

    if(path==true)
    {
        printf("\nWord found!\n");
        printf("Printing the search path: \n");
        for(int i = 0; i < bSize; i++){
            for(int j = 0; j < bSize; j++){
                printf("%d ", *(*(foundArr+i)+j));
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nWord not found!\n");
    }

}