#include<iostream>
using namespace std ;
void selection_sort(int arr[] ,int n){
  int min;
      for( int i=0;i<=n-2;i++){
    min=i;
        for(int j=i;j<=n-1;j++){
       if(arr[j]<arr[min]) min=j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main() {
    int arr[]={4,2,7,1,9};
    int n=5;
   
   selection_sort(arr,n);


for (int i=0;i<n;i++){
    cout<<arr[i];
}
return 0;
}