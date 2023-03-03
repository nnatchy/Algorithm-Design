#include<iostream>
#include<vector>
#include<cmath>
#define FOR(i,a,b)for(auto[i,i##_]=pair<int,const int>{(a),(b)};i<i##_;++i)

using namespace std;

int main() {
    int n,m,k,w,t,sum = 0;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    vector<int> p(m), h(m);
    FOR(i,0,m) scanf("%d",&p[i]);
    FOR(i,0,m) scanf("%d",&h[i]);
    while (k--) {
        scanf("%d",&t);
        FOR(j,0,m) {
            if (abs(t-p[j]) <= w && h[j] > 0) {
                h[j]--;
                break;
            }
        }
    }
    FOR(i,0,m) sum+=h[i];
    printf("%d",sum);
}