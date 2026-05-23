#include<stdio.h>
#define size 10
int top=-1;
int stack[size];
int push(int value){
   if (top==size-1){
    printf("stack overflow\n");
   }
   else{
   top++;
   stack[top]=value;
   return 0;
}

int pop(){
    if(top==-1){
        printf("stack does not have elements\n");
    }
    else{
    int del=stack[top];
    top--;
    printf("the deleted value is %d\n" ,del);
    return 0;
    }
}

int peep(){
    if(top==-1){
       printf("stack does not have elements\n");
       return 0;
    }
    else
    {
     printf("the top element of the stack is %d\n" ,stack[top]);
     return 0;
    }
}

int main() {
    int val;
    int user=1;
    while(user){
        printf("pick from the following options\n");
        printf("enter 1 to push\n");
        printf("enter 2 to peep\n");
        printf("enter 3 to pop\n");
        printf("enter 4 to exit\n");
    int choice;
    printf("enter choice\n");
    scanf("%d" ,&choice);
    }
    switch(choice) {
        case 1:
        printf("enter value to push\n");
        scanf("%d" ,&val);
        push(val);
        break;

        case 2:
        pop();
        break;

        case 3:
        peep();
        break;

        case 4:
        printf("exiting.....\n");
    }

    return 0 ;
}