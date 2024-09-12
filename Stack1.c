#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

int A[MAX_SIZE];
int top = -1;

void Push(char x){
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

int main(){
    char a[MAX_SIZE];
    printf("Enter the string: ");
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        Push(a[i]);
    }
    char str[100];
    int i=0;
    while(!IsEmpty()){
        str[i] = Top();
        Pop();
        i++;
    }
    int res = strcmp(a, str);
    if(res==0){
        printf("It is a palindrome");
    }else{
        printf("It is not a palindrome");
    }
}
