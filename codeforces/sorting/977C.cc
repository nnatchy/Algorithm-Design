#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;

int main() {
    int n, targetSize, inp;
    cin >> n >> targetSize;
    if (n == 0) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> vi;
    while (n--) {
        cin >> inp;
        vi.push_back(inp);
    }
    sort(vi.begin(), vi.end());
    if (targetSize == vi.size()) {
        cout << vi[targetSize - 1] << "\n";
    } else {
        if (targetSize == 0) {
            if (vi[0] - 1 == 0) cout << -1 << "\n";
            else cout << vi[0] - 1 << '\n';
            return 0;
        }
        int ind = targetSize - 1;
        if (vi[ind] == vi[ind+1]) {
            cout << -1 << '\n';
        } else {
            cout << vi[ind] << "\n";
        }
    }
}