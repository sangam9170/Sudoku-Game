#include<iostream>
using namespace std;
void print1(int n) {
     char startChar = 'A' + (n - 1);
    
    for (int i = 0; i < n; ++i) {
        for (char ch = startChar; ch >= startChar - i; --ch) {
            cout << ch << " ";
        }
        cout << endl;
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