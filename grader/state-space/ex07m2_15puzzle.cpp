#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<cmath>
#include<map>

#define ll long long
#define pll pair<ll, ll>
#define tmpPair pair<ll, vector<vector<ll> > >

using namespace std;

ll checkCost(vector<vector<ll> > &table) {
    ll cost = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (table[i][j] == 0) continue;
            cost += abs(i - (table[i][j] - 1) / 4) + abs(j - (table[i][j] - 1) % 4); // check move row, move col
        }
    }
    return cost;
}

pll findZero(vector<vector<ll> > &table) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (table[i][j] == 0) {
                return make_pair(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<ll> > table(4, vector<ll>(4, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> table[i][j];
        }
    }
    map<vector<vector<ll> >, ll > tableMove; // map that store type of table and its move count from input
    priority_queue<tmpPair, vector<tmpPair>, greater<tmpPair> > pq;
    pq.push(make_pair(0, table));
    tableMove[table] = 0;
    ll dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
    while (!pq.empty()) {
        tmpPair current = pq.top();
        pq.pop();
        vector<vector<ll> > tmpTable = current.second;
        ll cntMove = tableMove[tmpTable];
        ll costSearch = checkCost(tmpTable);
        if (costSearch == 0) {
            cout << cntMove << "\n";
            return 0;
        }
        pll zeroPos = findZero(tmpTable);
        ll r = zeroPos.first, c = zeroPos.second;
        for (int i = 0; i < 4; i++) {
            ll rr = dr[i] + r;
            ll cc = dc[i] + c;
            if (rr < 0 || rr >= 4 || cc < 0 || cc >= 4) continue;
            swap(tmpTable[rr][cc], tmpTable[r][c]);
            if (tableMove.find(tmpTable) == tableMove.end()) {
                ll newCostSearch = checkCost(tmpTable);
                tableMove[tmpTable] = cntMove + 1;
                pq.push(make_pair(newCostSearch + cntMove + 1, tmpTable));
            }
            swap(tmpTable[rr][cc], tmpTable[r][c]);
        }
    }
}