#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(){
        val=0;
        next=NULL;
        prev=NULL;
    }
}
class deque{
    private:
    Node* front;
    Node* rear;
    public:

    deque(){
        front=NULL;
        rear=NULL;
    }

    void enqueuefront(int val){
        Node* newnode=new Node(val);
        if(front==NULL){
            front=rear=newnode;
        }
        else{
            newnode->next=front;
            front->prev=newnode;
            front=newnode;
        }
        cout<<val<<"enqueue succesfully"<<endl;
    }

    void enqueuerear(int val){
        Node* newnode=new Node(val);
        if(rear==NULL){
            rear=front=newnode;
        }
        else{
            rear->next=newnode;
            newnode->prev=rear;
            rear=newnode;
        }
        cout<<val<<"inserted at reat succesfully"<<endl;
    }

    void dequeuefront(){
        if(front==NULL){
            cout<<"deque is empty"<<endl;
        }
        Node* temp=front;
        if(front==rear){
            front=rear=NULL;
        }
        else{
            front=front->next;
            front->prev=NULL;
        }
        delete temp;
    }
    void dequeuerear(){
        if(rear==NULL){
            cout<<"deque is empty"<<endl;
        }
        Node* temp=rear;
        if(front==rear){
            front=rear=NULL;
        }
        else{
            rear=rear->prev;
            rear->next=NULL;
        }
        delete temp;    
    }
}