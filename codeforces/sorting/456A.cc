#include<iostream>
#include<queue>
#include<stack>

#define pii pair<int,int>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pii> pq;
    while (n--) {
        int a, b;
        cin >> a >> b;
        pq.push(make_pair(a, b));
    }
    int quality = pq.top().second;
    bool check = false;
    pq.pop();
    while (!pq.empty()) {
        if (pq.top().second > quality) {
            check = true;
            break;
        }
        quality = pq.top().second;
        pq.pop();
    }
    if (check) cout << "Happy Alex" << "\n";
    else cout << "Poor Alex" << "\n";
}