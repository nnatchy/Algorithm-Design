#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, first;
    cin >> n >> first;
    vector<int> v; v.push_back(first); n--;
    int cnt = 0;
    int low = first;
    int high = first;
    while (n--) {
        int score;
        cin >> score;
        if (score < low) {
            low = score; cnt++;
        } else if (score > high) {
            high = score;
            cnt++;
        }
        v.push_back(score);
    }
    cout << cnt << "\n";
}