#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mx = n >= m ? n : m;
    int mn = n >= m ? m : n;
    int cnt = 0;
    // 3 5
    for (int i = 0; i <= mn; i++) {
        int t = mn - i;
        double check = sqrt(t);
        if (floor(check) != ceil(check)) continue;
        if (check + i * i == mx) cnt++;
    }
    cout << cnt << "\n";
}