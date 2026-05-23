#include<iostream>
#include<vector>
using namespace std;
int func(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return j;
}
 void quicksort(vector<int> &arr,int low,int high){
    if(low<high){
       int pindex= func(arr,low,high);
       quicksort(arr,low,pindex-1);
       quicksort(arr,pindex+1,high);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int low=0,high=n-1;
    quicksort(arr,low,high);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;

}