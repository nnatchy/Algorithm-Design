#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

ll get_sum(vector<ll> &sumV, ll a, ll b) {
    return a == 0 ? sumV[b] : sumV[b] - sumV[a-1];
}

ll mss(vector<ll> &vll, ll start, ll stop, vector<ll> &sumV) {
    if (start == stop - 1) return vll[start];
    ll mid = (start + stop) / 2;

    ll r1 = mss(vll, start, mid, sumV);
    ll r2 = mss(vll, mid, stop, sumV);

    ll max_sum_left = get_sum(sumV, mid - 1, mid - 1);
    for (int i = start; i < mid - 1; i++) {
        max_sum_left = max(max_sum_left, get_sum(sumV, i, mid - 1));
    }

    ll max_sum_right = get_sum(sumV, mid, mid);
    for (int j = mid + 1; j < stop; j++) {
        max_sum_right = max(max_sum_right, get_sum(sumV, mid, j));
    }
    ll r3 = max_sum_left + max_sum_right;
    return max(max(r1, r2) , r3);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, inp;
    cin >> N >> inp;
    vector<ll> vll, sumV;
    vll.push_back(inp); sumV.push_back(inp);
    ll sum = inp;
    for (int i = 1; i < N; i++) {
        cin >> inp;
        sum += inp;
        sumV.push_back(sum); vll.push_back(inp);
    }
    ll ans = mss(vll, 0, N, sumV);
    cout << ans << "\n";
}