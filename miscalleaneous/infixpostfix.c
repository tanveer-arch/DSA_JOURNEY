#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top = -1;

char output[100] = {'\0'};

int input_precedence(char ch){            
    
    if (ch=='+'||ch=='-'){
        return 1;
    }
    
    else if(ch=='*'||ch=='/'){
        return 3;
    }
    else if(isdigit(ch)){
        return 7;
    }
    else if(ch=='^'){
        return 6;
    }
    else if(ch=='('){
        return 9;
    }
    else if(ch==')'){
        return 0;
    }
    else{
        return -1;
    }
    
}

int output_precedence(char ch){         

    if (ch=='+'||ch=='-'){
        return 2;
    }
    else if(isdigit(ch)){
        return 8;
    }
    else if(ch=='*'||ch=='/'){
        return 4;
    }
    else if(ch=='^'){
        return 5;
    }
    else if(ch=='('){
        return 0;
    }
    else{
        return -1;
    }

}

void push(char ele){         //A function is defined to push an element 
    top++;
    stack[top] = ele;
}

char pop(){                  //A function is defined to pop an element
    top--;
    return stack[top+1];
}

void add(char ele){          //A function is defined to add the element in the ouptut string
    output[strlen(output)] = ele;
    output[strlen(output)+1] = '\0';
}



int main(){
    char exp[100];
    printf("Enter the Expression: ");
    scanf("%s",exp);

    //exp[strlen(exp)] = '#';  //Adding a terminating statement for while loop
    //exp[strlen(exp)+1] = '\0';


    int i=0;

    //push('(');
    while(exp[i]!='\0'){

        printf("'%s'\n",stack);
        printf("'%s'\n",output);
        printf("'%d'\n",i);

        printf("\n");

        
        char p;
        /*if (isdigit(exp[i])){
            add(exp[i]);              (5+2)+(4/7)*6
        }*/
        if(inp_prec(exp[i])>out_prec(stack[top])){
            push(exp[i]);
        }
        else{
            while(inp_prec(exp[i])<=out_prec(stack[top])){
                p = pop();
                if(p=='('&& exp[i]==')')
                break;
                
                add(p);
                
            }
            if(p!=')')
            push(exp[i]);
        }


        i++;
    }
    char j;
    while(top!=-1){
        j = pop();
        if(j!='(' && j!=')'){
            add(j);
        }
    }

    printf("%s",output);
}