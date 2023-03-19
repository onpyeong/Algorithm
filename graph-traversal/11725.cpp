//* BFS - 11725 <트리의 부모 찾기> 실버 2
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parent[100001] = {0};
vector<int> graph[100001];
int main() {
    int n;
    queue <int> q;

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    parent[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int i = 0; i < graph[node].size(); i++) {
            if(!parent[graph[node][i]]) {
                parent[graph[node][i]] = node;
                q.push(graph[node][i]);
            }
        }
    }

    for(int i = 2; i <= n; i++)
        cout << parent[i] << "\n";

    return 0;
}
