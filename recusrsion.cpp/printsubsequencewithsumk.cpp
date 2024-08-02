#include<bits/stdc++.h>
using namespace std;
void printf(int ind,vector<int>& ds,int s,int arr[],int n,int sum){
    if(ind==n){
        // checking contind of sum 
        if(s==sum){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return;
    }
    //take elemnt at particular index
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printf(ind+1,ds,s,arr,n,sum);
    //do not element of  that index
    ds.pop_back();
    s-=arr[ind];
    printf(ind+1,ds,s,arr,n,sum);
}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   vector<int>ds;
   int sum=2;
   printf(0,ds,0,arr,n,sum);
}