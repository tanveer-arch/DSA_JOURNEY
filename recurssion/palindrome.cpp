#include<iostream>
#include<string.h>
using namespace std;
bool palindrome(int i,string s,int n){
    if(i>=n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    palindrome(i+1,s,n);
}
int main() {
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
   cout<<palindrome(0,s,n);
  
    return 0;
}