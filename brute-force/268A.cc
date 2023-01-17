#include<iostream>
#include<vector>

#define pii pair<int,int>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pii> vp;
    while (n--) {
        int H, G;
        cin >> H >> G;
        vp.push_back(make_pair(H,G));
    }
    int cnt = 0;
    for (int i = 0; i < vp.size(); i++) {
        for (int j = 0; j < vp.size(); j++) {
            if (j == i) continue;
            if (vp[i].first == vp[j].second) cnt++;
        }
    }
    cout << cnt << "\n";
}