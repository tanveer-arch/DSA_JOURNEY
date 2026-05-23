#include<iostream>
using namespace std;

class Treenode{
        public:
        int value;
        Treenode *left;
        Treenode *right;

        Treenode(){
            value=0;
            left=NULL;
            right=NULL;
        }

        Treenode(int v){
            value=v;
            left=NULL;
            right=NULL;
        }
};

class Bst{
    public:
    Treenode *root;

    Bst(){
        root=NULL;
    }

    bool isempty(){
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void insertnode(Treenode *newnode){
        if(root==NULL){
            root=newnode;
        }
        else{
            Treenode *temp;
            temp=root;
            while(temp!=NULL){
                if(newnode->value==temp->value){
                    cout<<"value already exist"<<endl;
                    return ;
                }
                else if(newnode->value<temp->value && temp->left==NULL){
                    temp->left=newnode;
                    break; 
                }
                else if(newnode->value<temp->value){
                    temp=temp->left;
                }
                else if(newnode->value>temp->value && temp->right==NULL){
                    temp->right=newnode;
                    break ;
                }
                else{
                    temp=temp->right;
                }
            } 
        }
    }

    void printpreorder(Treenode *r){
        if(r==NULL){
            return ;
        }
        cout<<r->value<<" ";
        printpreorder(r->left);
        printpreorder(r->right);
    }

    void printinorder(Treenode *r){
        if(r==NULL){
            return ;
        }
        printinorder(r->left);
        cout<<r->value<<" ";
        printinorder(r->right);
    }

    void printpostorder(Treenode *r){
        if(r==NULL){
            return ;
        }
        printpostorder(r->left);
        printpostorder(r->right);
        cout<<r->value<<" ";
    }

    Treenode* iterativesearch(int v){
        if(root==NULL){
            return NULL;
        }
        else{
            Treenode *temp;
            temp=root;
            while(temp!=NULL){
            if(temp->value==v){
                return temp;
            }
            else if(v<temp->value){
                temp=temp->left;
            }
            else {
                temp=temp->right;
            }
        }
        return NULL;
        }           
    }

    Treenode* recursivesearch(Treenode *r,int v){
        if(r==NULL || v==r->value){
            return r;
        }
        else{
            if(v<r->value){
                recursivesearch(r->left,v);
            }
            else{
                recursivesearch(r->right,v);
            }
        }
    }

    Treenode* deletenode(Treenode *r,int val){
        if(r==NULL){
        return r;
        }
        else if(val<r->value){
            r->left=deletenode(r->left,val);
        }
        else if(val>r->value){
            r->right=deletenode(r->right,val);
        }
        else{
            if(r->left==NULL){
               Treenode *temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
              Treenode *temp=r->left;
                delete r;
                return temp;
            }
            else{
               Treenode *temp=minnode(r->right);
               r->value=temp->value;
               r->right=deletenode(r->right,temp->value);
            }
        }
        return r;
    }

    Treenode* minnode(Treenode* r){
        while(r->left!=NULL){
            r=r->left;
        }
        return r;
    }


};

int main(){
    Bst obj;
    int choice,v;
  
    while(1){
        cout<<"1. insert node"<<endl;
        cout<<"2. search node"<<endl;
        cout<<"3. delete node"<<endl;
        cout<<"4. print bst values"<<endl;
        cout<<"5. clear screen"<<endl;
        cout<<"0. exit program"<<endl;
        cout<<"enter choice"<<endl;
        cin>>choice;
          Treenode *newnode=new Treenode();

        switch(choice){
            case 0:
            return 0;
            case 1:
            cout<<"INSERT"<<endl;
            // insertion code
            cout<<"enter value of node to be inserted"<<endl;
            cin>>v;
            newnode->value=v;
            obj.insertnode(newnode);
            break;
            case 2:
            cout<<"SEARCH"<<endl;
            // search code
            int n;
            cout<<"enter value to be searched"<<endl;
            cin>>n;
            cout<<"iteratively searched"<<endl;
            if(obj.iterativesearch(n)){
                cout<<"found"<<endl;
            }
            else{
                cout<<"not found"<<endl;
            }

            cout<<"recursively searched"<<endl;
            if(obj.recursivesearch(obj.root,n)){
                cout<<"found"<<endl;
            }
            else{
                cout<<"not found"<<endl;
            }

            break;
            case 3:
            cout<<"delete"<<endl;
            // deletion code
            int del;
            cout<<"enter value of the node which is to be deleted"<<endl;
            cin>>del;
            obj.deletenode(obj.root,del);
            
            break;
            case 4:
            cout<<"print bst values"<<endl;
            // print bst values code
            obj.printpreorder(obj.root);
            cout<<endl;
            obj.printinorder(obj.root);
            cout<<endl;
            obj.printpostorder(obj.root);
            cout<<endl;
            break;
            case 5:
            cout<<"clear screen"<<endl;
            // insertion code
            break;
            default:
            cout<<"invalid option"<<endl;
        }
    }



    return 0 ;
}