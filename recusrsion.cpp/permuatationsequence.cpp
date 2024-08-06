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
#define fra(a, n) for(int i = 0; n && i < n; i++) cin >> a[i]
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
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.pb(i);
        }
        nums.pb(n);
        string ans = "";
        k = k - 1;
        while (true) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.empty()) {
                break;
            }
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution sol;
        cout << sol.getPermutation(n, k) << endl;
    }
    return 0;
}
