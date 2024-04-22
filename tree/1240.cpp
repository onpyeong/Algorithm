#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > adj[1005];
int dist[1005];

int bfs(int u, int v) {
    int dis = 0;
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == v) {
            return dist[v];
        }
        for(auto nxt : adj[cur]) {
            if(dist[nxt.first] != -1) continue;
            q.push(nxt.first);
            dist[nxt.first] = dist[cur] + nxt.second;
        }
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i < N; i++) {
        int u, v, dis;
        cin >> u >> v >> dis;
        adj[u].push_back({v, dis});
        adj[v].push_back({u, dis});
    }
    
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        fill(dist, dist + N + 1, -1);
        cout << bfs(u, v) << "\n";
    }

    return 0;
}
