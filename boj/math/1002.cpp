#include <iostream>
#include <cmath>

using namespace std;

int T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x1, y1, r1, x2, y2, r2;
  
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(r1 == r2 && x1 == x2 && y1 == y2) {
      cout << "-1\n";
      continue;
    }
    if(r1 > r2) {
      int t = r2;
      r2 = r1;
      r1 = t;
    }
    if(r1 + r2 == d|| r2  - r1 == d) {
      cout << "1\n";
      continue;
    }
    if(d == 0 || r2  - r1 > d || r1 + r2< d) {
      cout << "0\n";
      continue;
    }
    cout << "2\n";
  }
  return 0;
}
