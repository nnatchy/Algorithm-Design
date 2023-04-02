#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dijkstra(vector<pair<int, int> > graph[], int src, int target, int V){
    // min heap
    priority_queue<pair <int,int> , vector<pair<int,int > >, greater<pair<int,int> > > pq;
    vector<int> dist (V, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0,src));

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for (auto x : graph[u]){
            int v = x.first;
            int wt = x.second;
            if (dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v],v));
            }
        }
        if (u == target) return dist[u];
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k,v,start,a,b,w;
    cin >> n >> m >> k;
    cin >> v;

    vector<int> target;
    while (k--){
        cin >> start;
        target.push_back(start);
    }

    vector<pair<int,int> > graph[n+1];
    while (m--){
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b,w));  
    }

    int ans = INT_MAX;
    for (auto start : target){
        int tmp = dijkstra(graph, start, v, n);
        ans = min(ans, tmp);
    }

    cout << ans << "\n";
}