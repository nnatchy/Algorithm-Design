#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void recur(map<int,int> ord, vector<string> &output, int n, int x) {
    if (ord.find(x) == ord.end()) {
        
    }
    for (int i = 0; i < n; i++) {
        recur(ord, output, n, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, int> ord;
    for (int i = 0; i < n; i++) {
        int last, first;
        cin >> last >> first;
        ord[last] = first;
    }
    vector<string> outp;
    for (int i = 0; i < n; i++) {
        recur(ord, outp, n, i)
    }
}