#include <iostream>

using namespace std;

long long X, Y;
int Z;

long long binary_search() {
  long long s = 0, e = X + 1;
  long long mid;
  int newZ;
  while(s + 1 < e) {
    mid = (s + e) / 2;
    newZ = ((Y + mid) * 100) / (X + mid);
    if(Z == newZ) {
      s = mid;
    }else { // 승률이 더 크면
      e = mid;
    }
  }
  return e;
}

int main() {
    cin >> X >> Y;
    Z = (Y * 100) / X; // 버림
    
    if(Z >= 99)
      cout << -1;
    else
      cout << binary_search() << "\n";
    return 0;
}
