#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V, E, K;
vector<pair<int, int>> adj[20005];
int dist[20005];

void find_minDist() {
  priority_queue<pair<int, int>> pq;
  int cur, cost;
  
  pq.push({0, K});
  dist[K] = 0;
  while(!pq.empty()) {
    cur = pq.top().second;
    cost = -pq.top().first;
    pq.pop();
    
    if(dist[cur] < cost)
        continue;
    
    for(pair<int, int> nxt : adj[cur]) {
      if(dist[nxt.first] > dist[cur] + nxt.second) {
        dist[nxt.first] = dist[cur] + nxt.second;
        pq.push({-dist[nxt.first], nxt.first});
      }
    }
    
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int u, v, w;
  
  cin >> V >> E;
  cin >> K;
  for(int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  fill(dist, dist + V + 1, 1e9);
  find_minDist();
  for(int i = 1; i <= V; i++) {
    if(dist[i] == 1e9)
        cout << "INF\n";
    else
        cout << dist[i] << "\n";
  }
  return 0;
}
