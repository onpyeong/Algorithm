#include <iostream>

using namespace std;

int n;
int dp[50002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++) {
      dp[i] = i;
      for(int j = 1; j * j <= i; j++) {
        if(dp[i] > dp[i - j * j] + 1)
          dp[i] = dp[i - j * j] + 1;
      }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
