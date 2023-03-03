#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int
#define pll pair<ll, ll>


using namespace std;

bool sortVp(pll &x, pll &y) {
    return x.first > y.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N;
    cin >> N;
    vector<pll> vp(N);
    for (auto &x : vp) {
        cin >> x.first >> x.second;
    }
    sort(vp.begin(), vp.end(), sortVp);
    int cnt = 1;
    pll max = vp[0];
    for (int i = 1; i < vp.size(); i++) {
        // cout << vp[i].first << "\t" << vp[i].second << "\n";
        pll tmp = vp[i];
        if (tmp.second > max.second) {
            max = tmp;
            cnt++;
        }
        else if (tmp.second <= max.second && tmp.first > max.first) cnt++;
    }
    cout << cnt << "\n";
}
