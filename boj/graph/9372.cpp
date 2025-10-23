#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
int a, b;
vector<int> adj[1001];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      cin >> N >> M;
      
      for(int i = 1; i <= N; i++) {
        adj[i].clear();
      }
      
      for(int j = 0; j < M; j++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      
      cout << N - 1 << '\n';
    }
    return 0;
}
