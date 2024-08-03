// AUTHORS: SANGAM SINGH

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
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int rem = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev < INT_MIN / 10)) return 0;
            if (rev == INT_MAX / 10 && rem > 7) return 0;
            if (rev == INT_MIN / 10 && rem < -8) return 0;
            rev = rev * 10 + rem;
        }
        
        return rev;
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
        int x;
        cin >> x;
        
        Solution sol;
        int result = sol.reverse(x);
        
        cout << result << endl;
    }
    return 0;
}
