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

void subsetsum(int ind, int s, vector<int>& nums,vector<int>& ans) {
    if(ind == nums.size()) {
            ans.push_back(s);
            return;
        }
        //pick
        subsetsum(ind+1,s+nums[ind],nums,ans);
        //not pick
        subsetsum(ind+1,s,nums,ans);
    }


int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        fra(a, n);
        vi ans;
        subsetsum(0,0, a, ans);
        srt(ans);
        for(auto it:ans){
            cout<<it<<" ";
        }
        
    }
}