#include<iostream>
#include<queue>
#include<stack>
#include<vector>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll arr[505][505];

// BFS

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll r, c, T;
    cin >> r >> c >> T;
    queue<pll> q;
    ll cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
                cnt++;
            }
        }
    }
    vector<vector<ll> > adjMatrix(r, vector<ll>(c, 0));
    ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
    for (int i = 0; i < T; i++) {
        queue<pll> nextDay;
        while (!q.empty()) {
            pll current = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                ll rr = current.first + dr[j];
                ll cc = current.second + dc[j];
                if (rr < 0 || rr >= r || cc < 0 || cc >= c || arr[rr][cc] == 2 || arr[rr][cc] == 1) continue;
                else {
                    arr[rr][cc] = 1;
                    nextDay.push(make_pair(rr, cc));
                    cnt++;
                }
            }
        }
        q = nextDay;
    }
    cout << cnt << "\n";
}