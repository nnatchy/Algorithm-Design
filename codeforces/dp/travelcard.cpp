#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = min(dp[i], dp[i - 1] + 20);
		int pos = lower_bound(t.begin(), t.end(), t[i - 1] - 89) - t.begin();
		dp[i] = min(dp[i], dp[pos] + 50);
		pos = lower_bound(t.begin(), t.end(), t[i - 1] - 1439) - t.begin();
		dp[i] = min(dp[i], dp[pos] + 120);
		cout << dp[i] - dp[i - 1] << '\n';
	}
	return 0;
}