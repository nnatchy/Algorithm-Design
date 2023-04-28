#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<tuple>
#include<iomanip>

#define ll long double
#define pll pair<ll, ll>
#define ppl pair<ll ,pll>
#define lll tuple<ll, ll, ll>
#define tmpPair pair<ll, vector<ll> >

using namespace std;

vector<lll> vl;

ll FKS(ll start, ll sumW) {
    ll retV = 0;
    for (int i = start; i < vl.size(); i++) {
        if (sumW >= get<0>(vl[i])) {
            sumW -= get<2>(vl[i]);
            retV += get<1>(vl[i]);
        } else {
            retV += (sumW / get<2>(vl[i])) * get<1>(vl[i]);
            sumW = 0;
            return retV;
        }
    }
    return retV;
}

pair<ll, ll> sumVW(vector<ll> &selected, ll stop) {
    ll sumV = 0, sumW = 0;
    for (int i = 0; i < stop; i++) {
        if (selected[i]) {
            sumV += get<1>(vl[i]);
            sumW += get<2>(vl[i]);
        }
    }
    return make_pair(sumV, sumW);
}

int main() {
    ll w, n;
    cin >> w >> n;
    ll capW = 0, capV = 0;
    vl.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> get<1>(vl[i]); // price
        capV += get<1>(vl[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> get<2>(vl[i]); // weight
        capW += get<2>(vl[i]);
    }
    for (int i = 0; i < n; i++) {
        get<0>(vl[i]) = get<1>(vl[i]) / get<2>(vl[i]);
    }
    sort(vl.begin(), vl.end(), greater<ll>()); // fknapsack        
    priority_queue<tmpPair, vector<tmpPair>, greater<tmpPair> > pq; // maxHeap
    vector<ll> selected(n, 0);
    selected.push_back(0); // cur idx
    pq.push(make_pair(FKS(0, capW), selected));
    ll maxV = -1e9;
    while (!pq.empty()) {
        tmpPair current = pq.top();
        pq.pop();
        ll ub = current.first;
        vector<ll> selected = current.second;
        ll len = selected[n];
        if (ub < maxV) break;
        selected[n] += 1;
        pll VW = sumVW(selected, len);
        ll curV = VW.first;
        ll curW = VW.second;
        if (len > n) continue;
        if (len == n) maxV = max(maxV, curV);
        pq.push(make_pair(curV + FKS(len + 1, capW - curW), selected)); // not choose
        selected[len] = 1; 
        ll chooseV = VW.first + get<1>(vl[len]);
        ll chooseW = VW.second + get<2>(vl[len]);
        if (chooseW <= capW) pq.push(make_pair(chooseV + FKS(len + 1, capW - chooseW), selected));
    }
    cout << fixed << setprecision(4) << maxV << "\n";
}