#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int a[20003];
int b[20003];
int ans;

int calc_cnt(int x) {
  int s = -1, e = M;
  int mid;
  
  while(s + 1 < e) {
    mid = (s + e) / 2;
    if(b[mid] < x) {
      s = mid;
    }else {
      e = mid;
    }
  }
  
  return s + 1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      ans = 0;
      cin >> N >> M;
      for(int j = 0; j < N; j++) {
        cin >> a[j];
      }
      for(int j = 0; j < M; j++) {
        cin >> b[j];
      }
      sort(a, a + N);
      sort(b, b + M);
      
      for(int j = 0; j < N; j++) {
        ans += calc_cnt(a[j]);
      }
      
      cout << ans << "\n";
    }
    return 0;
}
