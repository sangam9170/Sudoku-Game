#include<iostream>
using namespace std;
void print1(int n){
    int star=1;
    for(int i=0;i<n;i++){
        if(i%2==0) star=1;
        else star=0;
        for(int j=0;j<=i;j++){
            cout<<star;
            star=1-star;
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       print1(n);
      
    }
    return 0;
}