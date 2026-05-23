#include<stdio.h>
struct node(){
    int data;
    node *left;
    node *right;
};

struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
 void insert(struct node* root , int data,int choice){
    if(root==NULL) return ;
    if(root->data==parentval){
    printf("enter 1. for left and 2. for right\n");
    scanf("%d");
    if(choice==1){
        if(root->left==NULL){
        root->left=createnode(int data);
        printf("%d is inserted at left of %d\n",data,root->data);
        }
        else{
            insert(root->left,data);
            }
    }
    else if(choice==2){
        if(root->right==NULL){
        root->right=createnode(int data);
        printf("%d is inserted at right of %d\n",data,root->data);
    }
    else{
         insert(root->right,data);
    }
 }
}

int main() {
    int choice,data,parentval,side;
    printf("enter data to create first node\n");
    scanf("%d",&data);

    while (1){
        printf("enter 1. to insert node\n");
        printf("enter 2. to print inorder\n");
        printf("enter 3. to exit\n")
        printf("enter choice\n");
        scanf("%d" ,&choice);
    }
    if(choice==1){
        printf("enter data for parent node\n");
        scanf("%d" ,&parentval);
        printf("enter newnode value\n");
        scanf("%d" ,&data);
        printf("enter 1. for left and 2. for right of the %d" ,parentval);
        scanf("%d",&side);
            if (!insert(root, parentVal, data, side)) {
                printf("Parent %d not found!\n", parentVal);
            }
        }
        else if (choice == 2) {
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}