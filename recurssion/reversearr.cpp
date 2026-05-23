#include<iostream>
using namespace std;
 int arr[4]={1,2,3,4};
void reverse(int &x, int &y){
    if(x==y){
        return ;
    }
    reverse(x++,y--);
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}


int main() {
//  int arr[4]={1,2,3,4};
 int l=0,r=3;
 reverse(l,r);
 for(int i=0;i<4;i++){
    cout<<arr[i];
 }
 return 0;
}