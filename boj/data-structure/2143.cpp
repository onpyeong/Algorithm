#include <iostream>
#include <map>

using namespace std;

int T, n, m;
int a[1003];
int b[1003];
map<int, int> aSum;
map<int, int> bSum;
long long answer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    cin >> n;
    cin >> a[0];
    aSum[a[0]]++;
    for(int i = 1; i < n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
      aSum[a[i]]++;
    }
    cin >> m;
    cin >> b[0];
    bSum[b[0]]++;
    for(int i = 1; i < m; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
      bSum[b[i]]++;
    }
    
    for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
        aSum[a[j] - a[i]]++;
      }
    }
    for(int i = 0; i < m - 1; i++) {
      for(int j = i + 1; j < m; j++) {
        bSum[b[j] - b[i]]++;
      }
    }
    
    for(auto x : aSum) {
      if(bSum.find(T - x.first) != bSum.end()) {
        answer += bSum[T - x.first] * (long long)x.second;
      }
    }
    
    cout << answer << "\n";
    return 0;
}
