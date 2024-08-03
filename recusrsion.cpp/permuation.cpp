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
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define cnt(k) count(arr, arr + n, k)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

class Solution {
public:
    void solve(int ind, vi& nums, vvi& ans) {
        // if(ds.size()==nums.size()){
        //     ans.push_back(ds);
        //     return;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(!mp[i]){
        //         ds.push_back(nums[i]);
        //         mp[i]=1;
        //         solve(ds,nums,ans,mp);
        //         mp[i]=0;
        //         ds.pop_back();
        //     }
        // }
        if(ind == nums.size()) {
            ans.pb(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]);
            solve(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vvi permute(vi& nums) {
        vvi ans;
        // vector<int>ds;
        // vector<int>mp(nums.size(),0);
        solve(0, nums, ans);
        return ans;
    }
};

int main() {
    fast_io;
    // Uncomment the following lines if input/output files are needed
    // read;
    // write;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi nums(n);
        fra(nums, n);
        
        Solution sol;
        vvi result = sol.permute(nums);
        
        for(const auto& perm : result) {
            for(int num : perm) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
