#include <iostream>

using namespace std;

int N, M, B;
int map[501][501];
int low = 10000, high = 0;
int minCost = 1e9;
int height = -1;

int calc_min_cost(int h) {
  int b = B;
  int cnt;
  int cost = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cnt = h - map[i][j];
      if(cnt > 0) {
        b -= cnt;
        cost += cnt;
      }else if(cnt < 0) {
        b -= cnt;
        cost += 2 * -cnt;
      }
    }
  }
  if(b < 0)
    return 1e9;
  return cost;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cost; 
    
    cin >> N >> M >> B;
    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        cin >> map[i][j];
        low = min(low, map[i][j]);
        high = max(high, map[i][j]);
      }
    }
    
    for(int i = low; i <= high; i++) {
      cost = calc_min_cost(i);
      if(cost <= minCost && i > height) {
        minCost = cost;
        height = i;
      }
    }
    
    cout << minCost << " " << height;
    return 0;
}
