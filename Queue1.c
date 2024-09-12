#include<stdio.h>
#include <stdbool.h>
#define N 100

int a[N];
int front = -1;
int rear = -1;

bool IsEmpty(){
    if(front==-1&&rear==-1){
        return true;
    }else{
        return false;
    }
}

void Enqueue(int x){
    if((rear+1)%N==front){
            printf("Queue is full");
            return;
    }
    if(IsEmpty()){
        front = 0;
        rear= 0;
    }
    else{
        rear = (rear+1)%N;
    }
    a[rear]=x;
}

void Dequeue(){
    if(IsEmpty()){
        return;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front = (front+1)%N;
    }
}
void Display()
{
    if (IsEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", a[i]);
        i = (i + 1) %N;
    }
    printf("%d\n", a[rear]);
}
Front(){
return a[front];
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Display();
    printf("Dequeued element: %d\n", Front());
    Dequeue();
    Display();
    return 0;
}
