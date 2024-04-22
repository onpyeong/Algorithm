#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32005];
int indegree[32005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]) {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    } 

    return 0;
}
