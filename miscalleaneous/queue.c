#include<stdio.h>

int queue[10];
int front = -1 , rear = -1;

int enqueue(int ele){
    if(rear == -1){
        rear++;
        front++;
        queue[rear] = ele;
        return 1;
    }
    if(rear>10){
        printf("Overflow Error.....");
        return 0;
    }
    rear++;
    queue[rear] = ele;
    return 1;
}

int dequeue(){
    if(front == rear){
        printf("Underflow Error....");
        return -1;
    }
    front++;
    return queue[front-1];
}

void display(){
    for(int i=front;i<rear+1;i++){
        printf("%d\n",queue[i]);
    }
}

int main(){
enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    dequeue();
    display();


}