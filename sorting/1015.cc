#include<iostream>
#include<queue>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long  all = 0;
    priority_queue<int> vi;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        all += a;
        vi.push(a - b);
    }
    long long cnt = 0;
    if (all <= m) {
        cout << 0 << "\n";
        return 0;
    }
    while (!vi.empty()) {
        int x = vi.top();
        all -= x;
        cnt++;
        vi.pop();
        if (all <= m) {
            cout << cnt << "\n";
            break;
        }
    }
    if (all > m) cout << -1 << '\n';
}