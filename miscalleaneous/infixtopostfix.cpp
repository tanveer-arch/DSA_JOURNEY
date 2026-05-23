#include<iostream>
#include<stack>
#include<string>
using namespace std;

int f(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 3;
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
        return 7;
    }
}

    int g(char ch){
        if(ch=='+' || ch=='-'){
        return 2;
    }
    else if(ch=='*' || ch=='/'){
        return 4;
    }
    else if(ch=='^'){
        return 5;
    }
    else if(ch=='('){
        return 0;
    }
    else{
        return 8;
    }
    }

    string infixtopostfix(string &infix){
        stack<char>st;
        string postfix="";
        infix=infix+')';
        st.push('(');
        for(char ch:infix){
            while(f(ch)<g(st.top())){
                postfix+=st.top();
                st.pop();
            }
            if(f(ch)>g(st.top())){
                st.push(ch);
            }
            else if(f(ch)==g(st.top())){
                st.pop();
            }

        }
        return postfix;
    }

    int main (){
        cout<<"enter infix expression"<<endl;
        string infix;
        cin>>infix;
        cout<<infixtopostfix(infix)<<endl;
        return 0 ;

    }