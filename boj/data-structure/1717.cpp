#include <iostream>

using namespace std;

int n, m;
bool oper;
int a, b;
int p[1000003];

int find_parent(int x) {
  if(x == p[x])
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
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
      p[i] = i;
      
    for(int i = 0; i < m; i++) {
      cin >> oper >> a >> b;
      if(!oper) {
        union_parent(a, b);
      }else {
        if(find_parent(a) != find_parent(b)) {
          cout << "NO\n";
        }else {
          cout << "YES\n";
        }
      }
    }
    return 0;
}
