#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int abs(int n){
    if (n < 0) return -n;
    else return n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k,w,p,h,t;
    unordered_map<int,int > pos2mon;
    vector<int> pos;

    cin >> n >> m >> k >> w;

    for (size_t i=0; i<m; i++){
        cin >> p;
        pos.push_back(p);
    }

    for (auto x: pos){
        cin >> h;
        pos2mon[x] += h;
    }

    for (size_t i=0; i<k; i++){
        cin >> t;
        for (int x : pos){
            if (abs(x-t) <= w && pos2mon[x] > 0){
                pos2mon[x] -= 1;
                break;
            }
        }
    }

    int sum = 0;
    for (auto x: pos2mon){
        sum += x.second;
    }

    cout << sum << "\n";
}