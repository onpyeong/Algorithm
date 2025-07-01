#include <iostream>

using namespace std;

int N;
bool a[64][64];

void compress(int sx, int sy, int len) {
  if(len == 1) {
    cout << a[sx][sy];
    return;
  }
  bool isSame = true;
  for(int i = sx; i < sx + len; i++) {
    for(int j = sy; j < sy + len; j++) {
      if(a[sx][sy] != a[i][j]) {
        isSame = false;
        break;
      }
    }
    if(!isSame) {
      break;
    }
  }
  if(isSame) {
    cout << a[sx][sy];
    return;
  }
  cout << "(";
  int halfLen = len / 2;
  compress(sx, sy, halfLen);
  compress(sx, sy + halfLen, halfLen);
  compress(sx + halfLen, sy, halfLen);
  compress(sx + halfLen, sy + halfLen, halfLen);
  cout << ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string row;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> row;
      for(int j = 0; j < N; j++) {
        a[i][j] = row[j] - '0';
      }
    }
    
    compress(0, 0, N);
    return 0;
}
