#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> visit[20005];
vector<int> adj[20005];

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = {1, 1};
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]) {
            if(visit[nxt].second == 0) {
                q.push(nxt);
                visit[nxt].first = nxt;
                visit[nxt].second = visit[cur].second + 1;
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    bfs();
    
    sort(visit, visit + N + 1, compare);

    int cnt = 0;
    while(visit[0].second == visit[cnt].second){
        cnt++;
    }
    
    cout << visit[0].first << " " << visit[0].second - 1 << " " << cnt;
    return 0;
}
