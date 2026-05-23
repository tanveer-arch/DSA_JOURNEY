#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
class treenode{
    public:
    int val;
    treenode *left;
    treenode *right;

    treenode(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

class solution{
    int preorderin;
    unordered_map<int,int>inorderin;

   public:
    treenode* buildtreehelper(vector<int>& preorder,vector<int>& inorder,int instart,int inend){
        if(instart>inend){
            return NULL;
        }

        int rootval=preorder[preorderin];
        treenode *root=new treenode(rootval);
        preorderin++;

        int pos=inorderin[rootval];

      root->left=buildtreehelper(preorder,inorder,instart,pos-1);
      root->right=buildtreehelper(preorder,inorder,pos+1,inend);
      return root;
    }

    treenode* buildtree(vector<int>& preorder,vector<int>& inorder){
        preorderin=0;
        for(int i=0;i<inorder.size();i++){
            inorderin[inorder[i]]=i;
        }
        return buildtreehelper(preorder,inorder,0,inorder.size()-1);
    }
};

void printinorder(treenode *r){
        if(r==NULL){
            return ;
        }
        printinorder(r->left);
        cout<<r->val<<" ";
        printinorder(r->right);
}

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    solution obj;
    treenode *root=obj.buildtree(preorder,inorder);
    cout << "Inorder traversal of constructed tree: ";
    printinorder(root);
    return 0;

}