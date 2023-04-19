#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

// similar to coin 2 in leetcode  

int main() {
    int n;
    cin >> n;
    vector<int> store(n + 1, 0);
    store[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j - i >= 0) store[j] = store[j] + store[j - i];
        }
    }
    cout << store[n] << "\n";
}