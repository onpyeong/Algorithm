#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int edge_size, idx;
vector<int> adj[20003];
bool visit[20003];
vector<int> d;

void bfs(int x) {
    queue<pair<int, int>> q;
    q.push({x, 0});
    visit[x] = true;
    
    while(!q.empty()) {
        int nx = q.front().first;
        int dist = q.front().second;
        q.pop();
        for(int nxt : adj[nx]) {
            if(visit[nxt])
                continue;
            q.push({nxt, dist + 1});
            visit[nxt] = true;
            d.push_back(dist + 1);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    edge_size = edge.size();
    for(int i = 0; i < edge_size; i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    sort(d.begin(), d.end(), greater<int>());
    idx = 1;
    while(d[0] == d[idx]) {
        answer++; idx++;
    }
    
    return answer;
}
