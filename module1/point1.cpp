#include<stdio.h>
#include <stdlib.h>

int main() {
    
    // dynamically allocate memory for a single integer
    int *theme_color_code_ptr = (int*)malloc(sizeof(int));
    
    // check if memory allocation unsuccessful
    if (theme_color_code_ptr == NULL){
        printf("Memory allocation unsuccessful!");
        return 1;
    }
    
    // default the value to 0
    *theme_color_code_ptr = 0;
    printf("Default theme color code : %d\n", *theme_color_code_ptr);
    
    //variable to store choice
    int input;
    
    // loop to get a valid input
    while(1){
        printf("Enter your prefered color code (0,1,2) : ");
        
        // get the choice from user
        if(scanf("%d", &input) != 1){
            // if choice is invalid clear the input stream
            while(getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }
        
        // if values are negative
        if (input < 0){
            printf("Choice cannot be negative\n");
        } else if (input > 2){
            printf("Values should be in 0-2 range\n");
        } else {
            *theme_color_code_ptr = input;
            break;
        }
    }
	
	// verify the choice
	printf("Theme color code : %d\n", *theme_color_code_ptr);
	
	// deallocate the memory 
	free(theme_color_code_ptr);
	theme_color_code_ptr = NULL;
	
	return 0;
}