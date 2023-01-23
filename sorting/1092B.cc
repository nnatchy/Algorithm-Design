#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    priority_queue<int> pq;
    while (n--) {
        cin >> a;
        pq.push(a);
    }
    int cnt = 0;
    while (!pq.empty()) {
        int x = pq.top();  
        pq.pop();
        cnt += x - pq.top();
        pq.pop();
    }
    cout << cnt << "\n";
}