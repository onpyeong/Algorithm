#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int X, Y;
vector<pair<int, int>> points;
vector<pair<double, pair<int, int>>> edges;  
long long a, b;
int p[1003];
double answer;

int find_parent(int x) {
  if(p[x] == x)
    return x;
  return p[x] = find_parent(p[x]);
}

void union_parent(int x, int y) {
  x = find_parent(x);
  y = find_parent(y);
  if(x <= y)
    p[y] = x;
  else
    p[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
      cin >> X >> Y;
      points.push_back({X, Y});
      for(int j = 0; j < i; j++) {
        a = ((long long) (points[j].first - X)) *  (points[j].first - X);
        b = ((long long) (points[j].second - Y)) *  (points[j].second - Y);
        edges.push_back({sqrt(a + b), {i, j}});
      }
    }
    
    for(int i = 0; i < N; i++)
      p[i] = i;
    
    for(int i = 0; i < M; i++) {
      cin >> X >> Y;
      union_parent(X - 1, Y - 1);
    }
    
    sort(edges.begin(), edges.end());
    int edges_size = edges.size();
    
    for(int i = 0; i < edges_size; i++) {
      X = edges[i].second.first;
      Y = edges[i].second.second;
      if(find_parent(X) != find_parent(Y)) {
        union_parent(X, Y);
        answer += edges[i].first;
      }
    }
    
    printf("%.2f\n", answer);
    
    return 0;
}
