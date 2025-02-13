#include <iostream>

using namespace std;

int T, V, E, x, y, p, c, commonAnc;
int adj[10005][3];
int ancestor[2][10005];
int sub[10005];
int i, j;
int parent[10005];

void init() {
    for(int i = 1; i <= V; i++) {
        adj[i][0] = 0;
    }
    i = j = 0;
}

void dfs(int cur) {
    int nxt;
    sub[cur] = 1;
    for(int i = 0; i < adj[cur][0]; i++) {
        nxt = adj[cur][i + 1];
        if(nxt == 0)
            break;
        dfs(nxt);
        sub[cur] += sub[nxt];
    }
}

int findCommonAnc() {
    int now = parent[x];
    while(now != 1) {
        ancestor[0][i++] = now;
        now = parent[now];
    }
    ancestor[0][i++] = now;
    
    now = parent[y];
    while(now != 1) {
        ancestor[1][j++] = now;
        now = parent[now];
    }
    ancestor[1][j++] = now;

    i--;
    j--;
    while(ancestor[0][i] == ancestor[1][j]) {
        i--;
        j--;
        if(i < 0 || j < 0)
            break;
    }
    return ancestor[0][i + 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        init();
        cin >> V >> E >> x >> y;
        for(int i = 0; i < E; i++) {
            cin >> p >> c;
            parent[c] = p;
            adj[p][++adj[p][0]] = c;
        }
        commonAnc = findCommonAnc();
        dfs(commonAnc);
        cout << "#" << t << " " << commonAnc << " " << sub[commonAnc] << "\n";
    }
    return 0;
}
