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
    void solve(int i, int j, vvi &a, int n, vector<string> &ans, string move, vvi &vis, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.pb(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vvi &mat) {
        int n = mat.size();
        vector<string> ans;
        vvi vis(n, vi(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if (mat[0][0] == 1) solve(0, 0, mat, n, ans, "", vis, di, dj);
        return ans;
    }
};

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vvi mat(n, vi(n));
        fra(mat[i], n);
        Solution sol;
        vector<string> result = sol.findPath(mat);
        for (const auto& path : result) {
            cout << path << endl;
        }
    }
    return 0;
}
