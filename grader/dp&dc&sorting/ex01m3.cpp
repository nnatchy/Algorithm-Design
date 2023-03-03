#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define ll long long int

using namespace std;

bool check(vector<ll> &chef, ll mid, ll inp) {
    ll ans = 0;
    for (int i = 0; i < chef.size(); i++) {
        ans += mid / chef[i];
    }
    return ans <= inp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, A;
    cin >> N >> A;
    vector<ll> chef(N);
    for (int i = 0; i < N; i++) cin >> chef[i];
    while (A--) {
        ll inp;
        cin >> inp;
        if (inp < chef.size()) {
            cout << 0 << "\n";
            continue;
        }
        inp -= N;
        ll lo = 1;
        ll hi = chef.back() * inp;
        ll ans = 0;
        int i = 0;
        while (lo < hi) {
            // printf("i: %d\n", ++i);
            ll mid = lo + (hi - lo) / 2;
            // printf("mid: %d\n", mid);
            if (!check(chef, mid, inp)) {
                hi = mid;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}

// using namespace std;
// ll queue_time(ll mid, vector<int> &chef, ll inp) {
//     ll time = 0;
//     for (auto &x : chef) {
//         time += mid / x;
//     }
//     return time;
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     ll N, A, T, inp;
//     cin >> N >> A;
//     vector<int> chef;
//     for (int i = 0; i < N; i++) {
//         cin >> inp;
//         chef.push_back(inp);
//     }
//     sort(chef.begin(), chef.end());
//     while (A--) {
//         cin >> inp;
//         if (inp < chef.size()) {
//             cout << 0 << "\n";
//             continue;
//         }
//         inp -= N;
//         ll start = 0;
//         ll stop = chef[chef.size() - 1] * inp;
//         while (start < stop) {
//             ll mid = (start + stop) >> 1;
//             if (inp > queue_time(mid, chef)) {
//                 start = mid + 1;
//             } else {
//                 stop = mid;
//             }
//         }
//         cout << stop << '\n';
//     }
// }