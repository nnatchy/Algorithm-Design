#include<iostream>
#include<queue>

#define ll long long
#define pll pair<ll,ll>
#define Q queue<pll>

using namespace std;

char arr[101][101];

// BFS

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll R, C;
    cin >> R >> C;
    ll dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<ll> > adjMat(R, vector<ll>(C, -1));
    adjMat[0][0] = 0;
    Q q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pll current = q.front();
        q.pop();
        if (current == make_pair(R - 1, C - 1)) break;
        for (int i = 0; i < 4; i++) {
            ll rr = current.first + dr[i];
            ll cc = current.second + dc[i];
            if (rr < 0 || cc < 0 || rr >= R || cc >= C || arr[rr][cc] == '#') continue;
            if ((adjMat[rr][cc] == 0) && (arr[rr][cc] = '.')) {
                adjMat[rr][cc] = adjMat[current.first][current.second] + 1;
                q.push(make_pair(rr, cc));
            }
        }
    }
    cout << adjMat[R - 1][C - 1] << "\n";
}

