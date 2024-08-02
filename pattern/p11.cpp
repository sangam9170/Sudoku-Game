#include<iostream>
using namespace std;
void print1(int n){
    int cnt=1;
  for(int i=1;i<=n;i++){
     for(int j=1;j<=i;j++){
        cout<<cnt<<" ";
        cnt++;
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