#include <iostream>

using namespace std;

// int w(int a, int b, int c) {
//   if (a <= 0 or b <= 0 or c <= 0)
//     return 1;

//   if (a > 20 or b > 20 or c > 20)
//       return w(20, 20, 20);
  
//   if (a < b and b < c)
//       return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  
//   return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
// }

int dp[23][23][23];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 0, b = 0, c = 0;
    
    //초기값 1로 도배
    for(int i = 0; i <= 20; i++) {
      for(int j = 0; j <= 20; j++) {
        fill(dp[i][j], dp[i][j] + 22, 1);
      }
    }
    
    for(int i = 1; i <= 20; i++) {
      for(int j = 1; j <= 20; j++) {
        for(int k = 1; k <= 20; k++) {
          if (i < j && j < k)
            dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
          else
            dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];         
        }
      }
    }
    
    while(true) {
      cin >> a >> b >> c;
      if(a == -1 && b == -1 && c == -1)
        break;
      
      cout << "w(" << a << ", " << b << ", " << c << ") = ";
      if (a <= 0 || b <= 0 || c <= 0) {
        cout << 1 << "\n";
        continue;
      }

      if (a > 20 || b > 20 || c > 20) {
        cout << dp[20][20][20] << "\n";
        continue;
      }

      cout << dp[a][b][c] << "\n";
    }
    
    return 0;
}
