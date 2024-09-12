#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(A[top]==MAX_SIZE-1){
        printf("Cannot push element as stack is full");
        return;
    }
    A[++top]=x;
}

void Pop(){
    if(top==-1){
        printf("Error: no element to pop");
        return;
    }
    top--;
}
int Top(){
    return A[top];
}
bool IsEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
void DecimalToBase(int decimal,int base){
    while(decimal>0){
        int remainder = decimal%base;
        Push(remainder);
        decimal = decimal/base;
    }
}

void PrintBase(int base){
    while (!IsEmpty()){
        int digit = Top();
        Pop();
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10);
        }
    }
}

int main() {
    int decimal, base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Enter the base (between 2 and 16): ");
    scanf("%d", &base);
    if (base < 2 || base > 16) {
        printf("Invalid base!\n");
        return 1;
    }
    DecimalToBase(decimal, base);
    printf("The number in base %d is: ", base);
    PrintBase(base);
    printf("\n");
    return 0;

}

