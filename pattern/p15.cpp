#include <iostream>
using namespace std;

void print2(int n){
    int space = 2 * n - 2;  // Adjust space to align properly
    for (int i = 0; i < n; i++) {
        // Star
        for (int j = 1; j <= i + 1; j++) {
            cout << "*";
        }
        // Space
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        // Star
        for (int j = 1; j <= i + 1; j++) {
            cout << "*";
        }
        space -= 2;  // Decrease the space count by 2 for each row
        cout << endl;
    }
}

void print1(int n){
    for (int i = 0; i < n; i++) {
        // Star
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }
        // Space
        for (int j = 0; j < 2 * i; j++) {
            cout << " ";
        }
        // Star
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        print1(n);
        print2(n);
    }
    return 0;
}
