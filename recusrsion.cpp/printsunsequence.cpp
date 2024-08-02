#include<bits/stdc++.h>
using namespace std;
void printf(int ind,vector<int>& ds,int arr[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
   
    //take elemnt at particular index
    ds.push_back(arr[ind]);
    printf(ind+1,ds,arr,n);
    //do not element of  that index
    ds.pop_back();
    printf(ind+1,ds,arr,n);
}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   vector<int>ds;
   printf(0,ds,arr,n);
}