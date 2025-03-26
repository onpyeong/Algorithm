#include <iostream>

using namespace std;

int n, m;
int cost[103][103];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  
  
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++) {
    fill(cost[i], cost[i] + n + 1, 1e9);
    cost[i][i] = 0;
  }
  
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    cost[a][b] = min(cost[a][b], c);
  }
  
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
      }
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << ((cost[i][j] == 1e9)? 0 : cost[i][j]) << " ";
    }
    cout << "\n";
  }

}
