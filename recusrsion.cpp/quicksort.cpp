//   AUTHORS: SANGAM SINGH

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vvll vector<ll>
#define vc vector<char>
#define vvc vector<vc>
#define vvp vector<pair<int, int>>
#define mii map<int, int>
#define pii pair<int, int>
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define fr(n) for(int i = 0; i < n; i++)
#define frk(n, k) for(int i = 0; i < n; i+=k)
#define fra(a, n) for(int i = 0; i < n; i++) cin >> a[i]
#define fr1(a, n) for(int i = a; i <= n; i++)
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define mn(v) *min_element(v.begin(), v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define cnt(k) count(arr, arr + n, k);
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
 int partition(vector<int>&arr,int l,int h){
    int pivot =arr[l];
    int i=l;
    int j=h;
    while(i<j){
        while(arr[i]<=pivot && i<h){
            i++;
        }
         while(arr[j]>pivot && j>l){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        swap(arr[l],arr[j]);
        return j;
    }
 }
void quick (vector<int>&arr,int l,int h){
       if(l<h){
        int pindex =partition(arr,l,h);
        quick(arr,l,pindex-1);
        quick(arr,pindex+1,h);
       }
}
int main() {
    fast_io;
    
    int t;
    cin >> t;
    while(t--) {
     int n;
        cin>>n;
        vi a(n);
        fra(a,n);
        quick(a,0,n-1);
        fr(n){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}