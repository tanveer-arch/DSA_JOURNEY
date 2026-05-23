#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*top=NULL;

void push(int data){
    struct node*newnode;    
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("heap overflow\n");
    }
    else{
       newnode->data=data;
       newnode->next=top;
       top=newnode; 
    }
}

int pop(){
    struct node*temp=top;
    if(top==NULL) {
        printf("stack is empty\n");
    }
    else{
        int val=temp->data;
        top=top->next;
        free(temp);
    return val;
}
}

int peep(){
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        return top->data;
    }
}

void display() {
    if(top==NULL) {
        printf("stack is empty\n");
    }
    else{
        struct node*temp=top;
        printf("stack elements :");
        while(temp!=NULL){
            printf("%d " ,temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    peep();
    display();
    return 0 ;

}