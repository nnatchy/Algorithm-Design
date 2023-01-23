#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
bool checkVirus(vector<int> vi, int k, bool res) {
    vector<int> v1, v2;
    for (int i = 0; i < vi.size() / 2; i++) {
        v1.push_back(vi[i]);
        v2.push_back(vi[vi.size() / 2 + i]);
    }
    if (k == 1) {
        if (res) {
            if ((v1[0] == 0 && v2[0] == 1) ||  (v1[0] == 1 && v2[0] == 0)) return true;
            else return false;
        }
        if (v1[0] == 0 && v2[0] == 1) return true;
        else return false;
    } else {
        vector<int> v3 = v1;
        reverse(v3.begin(), v3.end());
        return (checkVirus(v1, k-1, true) || checkVirus(v3, k-1, true)) && checkVirus(v2, k-1, false);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    while (n--) {
        int bit;
        vector<int> vi;
        for (int i = 0; i < pow(2, k); i++) {
            cin >> bit;
            vi.push_back(bit);
        }
        bool result = checkVirus(vi, k, false);
        if (result) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

}