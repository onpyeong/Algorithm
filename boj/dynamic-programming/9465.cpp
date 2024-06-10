#include <iostream>

using namespace std;

int sticker[2][1000005];
int dp[2][1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> sticker[i][j];
            }
        }
        
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for(int j = 2; j <= n; j++) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + sticker[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}
