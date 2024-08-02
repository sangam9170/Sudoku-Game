#include<iostream>
using namespace std;
void print1(int n){
  for(int i=1;i<=n;i++){
    char ch='A';
     for(int j=1;j<=i;j++){
        cout<<ch<<" ";
        ch++;
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