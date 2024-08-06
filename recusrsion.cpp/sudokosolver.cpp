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
    bool solve(vvc &board) {
        fr(board.size()) {
            for (int j = 0; j < board[0].size(); j++) { 
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // If no valid number found
                }
            }
        }
        return true; // If all cells are filled correctly
    }

    bool isValid(vvc &board, int row, int col, char c) {
        fr(9) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    void solveSudoku(vvc &board) {
        solve(board);
    }
};

int main() {
    fast_io;
    // Uncomment the following lines if input/output files are needed
    // read;
    // write;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution sol;
        vvc board(n, vc(n));
        fr(n) {
            for (int j = 0; j < n; j++) { 
                cin >> board[i][j];
            }
        }

        sol.solveSudoku(board);
        
        fr(n) {
            for (int j = 0; j < n; j++) { 
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
