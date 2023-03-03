#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// top left -> bottom right

void recur(vector<vector<int> > &vvi, int a, int b, int top, int bottom, int left, int right) {
    if (!a) {
        vvi[top][left] = b;
        return;
    } else {
        int row = (top + bottom) / 2;
        int col = (left + right) / 2;
        recur(vvi, a - 1, b, top, row, left, col); // Q1
        recur(vvi, a - 1, b - 1, top, row, col, right); // Q2
        recur(vvi, a - 1, b + 1, row, bottom, left, col ); // Q3
        recur(vvi, a - 1, b, row, bottom, col, right); // Q4
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int> > vvi;
    vector<int> vi(1 << a);
    for (int i = 0; i < pow(2, a); i++) vvi.push_back(vi);
    recur(vvi, a, b, 0, 1 << a, 0, 1 << a);
    for (auto vi : vvi) {
        for (int i = 0; i < vi.size(); i++) cout << vi[i] << " ";
        cout << "\n";
    }
}