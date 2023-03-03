#include<iostream>
#include<vector>

using namespace std;

void merge_sort(vector<int> &a, int l, int r, int cnt, int &k) {
    if (cnt == k) return;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    merge_sort(a, 0, a.size() - 1, 0, k);
    
}