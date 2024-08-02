#include<iostream>
using namespace std;
void print1(int n){
     for(int i=0;i<n;i++){
        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" "<<" ";
        }
        //star
        char ch='A';
        int a=((2*i+1)/2);
        for(int j=0;j<(2*i+1);j++){
            cout<<ch<<" ";
            if(j<a) ch++;
            else ch--;
           
        }
        //space
        for(int j=0;j<n-i-1;j++){
            cout<<" "<<" ";
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