#include <iostream>

using namespace std;

int N, M;
int a[1026][1026];
int sum[1026][1026];
int x1, y1, x2, y2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> a[i][j];
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
    }
  }
  
  for(int i = 0; i < M; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
  }
}
