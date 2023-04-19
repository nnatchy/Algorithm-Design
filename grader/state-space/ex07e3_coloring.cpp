#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std; 

bool isSafe(vector<vector<ll> > &adjMatrix, vector<ll> &colour, int checkColour, int pos) {
    for (auto &x : adjMatrix[pos]) {
        if (checkColour == colour[x]) return false;
    }
    return true;
}

bool solve(vector<vector<ll> > &adjMatrix, vector<ll> &colour, int max_colour, int n, int i) {
    if (i == n) return true;    
    for (int j = 0; j < max_colour; j++) {
        if (isSafe(adjMatrix, colour, j, i)) {
            colour[i] = j;
            if (solve(adjMatrix, colour, max_colour, n, i + 1)) return true;
            colour[i] = -1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, e;
    cin >> n >> e;
    vector<vector<ll> > adjMatrix(n);
    vector<ll> colour(n, -1);
    while (e--) {
        ll a, b;
        cin >> a >> b;
        adjMatrix[a].push_back(b);
        adjMatrix[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (solve(adjMatrix, colour, i, n, 0)) {
            cout << i << "\n";
            return 0;
        }
    }
}