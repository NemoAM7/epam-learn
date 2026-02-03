#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
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

int divide(int a, int b){
  if(b == 0){
    printf("Divide by zero is not defined!\n");
    return INT_MIN;
  }
  return a/b;
}


// function to calculate based on plugged in operation
int calculate(int a, int b, int(*operation)(int, int)){
  return operation(a, b);
}

int main(){
  
  // sample testcases
  printf("%d\n",calculate(3, 4, add));
  printf("%d\n",calculate(3, 4, subtract));
  printf("%d\n",calculate(3, 4, multiply));
  printf("%d\n",calculate(3, 4, divide));
  printf("%d\n",calculate(3, 0, divide));
  
  return 0;
}