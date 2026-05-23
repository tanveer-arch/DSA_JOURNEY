#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*head=NULL;

 void createlist(int n){
    int data;
    struct node *newnode,*temp;
    for(int i=0;i<n;i++){
    newnode=(struct node*)(malloc(sizeof(struct node)));
    if (newnode==NULL){
        printf("unable to allocate memory\n");
    }
        printf("enter data for %d node\n" ,i+1);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
        temp=newnode;
        head=newnode;
        }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
    }
}

void displaylist(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty\n");
        return ;
    }
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void todelete(int a){
    struct node *temp=head,*prev=NULL;
    
    if(head==NULL){
        printf("list is empty\n");
        return ;
    }

    if(head->data==a){
        head=head->next;
        free(temp);
        printf("node with value %d is deleted\n" ,a);
        return ;
    }

    while(temp!=NULL && temp->data!=a){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("node with value %d is not found\n" ,a);
    }
    else{
        prev->next=temp->next;
        free(temp);
        printf("node with value %d is deleted\n" ,a);
    }
}

void tosearch(int b){
    struct node *temp=head;
    int pos=1,found=0;

    while(temp!=NULL){
        if(temp->data==b){
            printf("element %d found at position %d\n",b,pos);
            found=1;
            break;
        }
        pos++;
        temp=temp->next;
    }

    if(!found){
        printf("element not found\n");
    }
}

int main() {
    int n;
    printf("enter number of nodes\n");
    scanf("%d" ,&n);
    createlist(n);
    int choices,a,b;
    printf("to delete a element press 1\n");
    printf("to search a element press 2\n");
    printf("to display list press 3\n");
    scanf("%d",&choices);
    switch(choices) {
        case 1:
        printf("enter value to be deleted\n");
        scanf("%d",&a);
        todelete(a);
        break;

        case 2:
        printf("enter value to search in list\n");
        scanf("%d",&b);
        tosearch(b);
        break;

        case 3:
        displaylist(head);
        break;
    }
    
    return 0 ;
}