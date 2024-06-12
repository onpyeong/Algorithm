#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[5005];
int d[5005];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start}); //가중치 합, 노드
    d[start] = 0;
    while(!pq.empty()) {
        int c = -pq.top().first; //최소힙
        int x = pq.top().second;
        pq.pop();
        if(d[x] < c)
            continue;
        for(pair<int, int> nxt : graph[x]) {
            int cost = d[x] + nxt.second;
            int nx = nxt.first;
            if(cost < d[nx]) {
                d[nx] = cost;
                pq.push({-cost, nx});
            }
        }
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    fill(d, d + n + 1, INF);
    
    cin >> s >> t;
    
    dijkstra(s);
    
    cout << d[t];

    return 0;
}
