#include <iostream>   
#include <vector>       
#include <queue>        
#include <utility>      
#include <functional>   
#include <limits>       

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    const int INF = numeric_limits<int>::max();
    vector<vector<pair<int,int>>> adj(V + 1); 
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(V + 1, INF);
    dist[K] = 0;

 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; 

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}
