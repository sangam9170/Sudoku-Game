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
    // bool issafe(int row,int col,vector<string>board,int n){
    //     int duprow=row;
    //     int dupcol=col;
    //     //check upperleft
    //     while(row>=0 && col>=0){
    //         if(board[row][col]=='Q')
    //         return false;
    //         row--;
    //         col--;
    //     }
    //     //check left part
    //     //restore original row and col
    //   col = dupcol;
    //   row = duprow;
    //     while(col>=0){
    //         if(board[row][col]=='Q'){
    //             return false;
    //         }
    //         col--;
    //     }
    //     //check bottom left part
    //      col = dupcol;
    //      row = duprow;
    //      while(row<n && col>=0){
    //         if(board[row][col]=='Q'){
    //             return false;
    //         }
    //         row++;
    //         col--;
    //      }
    //      return true;
    // }
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
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
        
        Solution sol;
        vector<vector<string>> result = sol.solveNQueens(n);
        
        for(const auto& solution : result) {
            for(const auto& row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
