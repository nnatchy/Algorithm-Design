#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, inp;
    cin >> N;
    vector<ll> vl;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        vl.push_back(inp);
        sum += inp;
    }
    ll maxSum = vl[0], curSum = vl[0], curMin = vl[0], minSum = vl[0];
    for (int i = 1; i < N; i++) {
        curSum = max(vl[i], curSum + vl[i]);
        maxSum = max(curSum, maxSum);
        curMin = min(vl[i], vl[i] + curMin);
        minSum = min(minSum, curMin);
    }
    cout << max(maxSum, sum == minSum ? maxSum : sum - minSum) << "\n"; 
}