#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[505];
int dist[505];
int n;
int ans = 0;

void bfs() {
    queue<int> q;
    fill(dist, dist + n + 1, -1);
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(dist[cur] > 0 && dist[cur] <= 2) {
            ans++;
        }else if(dist[cur] > 2) {
            break;
        }
        for(auto nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(adj[1].size() != 0) {
        bfs();
    }
    cout << ans;
    return 0;
}
