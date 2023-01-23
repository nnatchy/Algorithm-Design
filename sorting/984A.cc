#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dq;
    for (int i = 0; i < n; i++) {
        int inp;
        cin >> inp;
        dq.push_back(inp);
    }
    sort(dq.begin(), dq.end());
    if (n % 2 == 0) cout << dq[(dq.size() - 1) / 2] << "\n";
    else cout << dq[dq.size() / 2] << "\n";
}