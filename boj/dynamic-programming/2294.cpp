#include <iostream>
#include <set>

using namespace std;

int n, k;
int dp[10001];
set<int> coin;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int price;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
      cin >> price;
      coin.insert(price);
    }
    
    for(int i = 1; i <= k; i++) {
      dp[i] = 999999;
      for(int c : coin) {
        if(c > i) {
          break;
        }
        dp[i] = min(dp[i - c] + 1, dp[i]);
      }
    }
    
    cout << (dp[k] == 999999 ? -1 : dp[k]);
    
    return 0;
}
