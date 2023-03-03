#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int A, inp;
    cin >> A;
    vector<int> v;
    while (A--) {
        cin >> inp;
        v.push_back(inp);
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) cnt++;
        }
    }
    cout << cnt << "\n";
}