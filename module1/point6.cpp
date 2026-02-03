#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// Function Definitions for different arithmetic operations
int add(int a, int b){
  return a+b;
}

int subtract(int a, int b){
  return a-b;
}

int multiply(int a, int b){
  return a*b;
}


int main(){
  
  // Variable declaration
  int a,b,choice,result; 
  
  // Get operands from user
  printf("Enter two numbers : ");
  scanf("%d %d", &a, &b);
  
  // Get Operation from user
  printf("Choose an operation\n[1] Add\n[2] Subtract\n[3] Multiply\n");
  scanf("%d", &choice);
  
  // Define an array of function
  int (*operations[4]) (int,int) = {add, subtract, multiply};
  
  // Validate choice
  if (choice >= 1 && choice <= 4){
    // Index the correct function based on choice and display result
    result = operations[choice-1](a, b);
    printf("Answer is %d", result);
  } else {
    printf("Invalid choice!");
  }
  
  return 0;
}