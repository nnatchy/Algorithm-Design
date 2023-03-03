#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

void recur(map<int,int> &ord, vector<int> &sol, vector<bool> &used, int &n, int len) {
    if (len == n) {
        for (int i = 0; i < n; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && (ord.find(i) == ord.end() || used[ord[i]])) {
            used[i] = true;
            sol[len] = i;
            recur(ord,sol,used,n,len+1);
            used[i] = false;
        }
    }
}   

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, int> ord;
    for (int i = 0; i < m; i++) {
        int last, first;
        cin >> last >> first;
        ord[first] = last;
    }
    vector<int> sol(n, 0);
    vector<bool> used(n, false);
    recur(ord, sol, used, n, 0);
}