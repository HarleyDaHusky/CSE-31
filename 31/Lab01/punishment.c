#include <stdio.h> 
#include <stdbool.h>

int main()
{
    int a;
    int b;
    bool checkPoint1 = true;
    bool checkPoint2 = true;
    printf("Enter the number of repition for the punishment phrase: ");
    scanf("%d", &a);
    while(checkPoint1 == true){
        if(a <= 0){
            printf("You entered an invalid value for the number of repetitions!");
            printf("Enter the number of repetitions for the punishment phrase again: ");
            scanf("%d", &a);
        }
        else{
            checkPoint1 = false;
        }
    }
    printf("Enter the line where you wish to introduce the typo: ");
    scanf("%d", &b);
    while(checkPoint2 == true){
        if(b <= 0 || (b > a)){
            printf("You entered an invalid value for the type placement!");
            printf("Enter the line where you wish to introduce the typo again: ");
            scanf("%d", &b);
        }
        else{
            checkPoint2 = false;
        }
    }

    for(int i = 0; i < b-1; i++){
        printf("Coding in C is fun and interesting!\n");
    }
    printf("Cading in C is fun end intresting!\n");
    for(int i = b; i<a; i++){
        printf("Coding in C is fun and interesting!\n");
    }

    
	return 0;
} 