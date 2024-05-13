#define MAX 1000001
#include <iostream>

using namespace std;

int main()
{
    int n;
    int dp[MAX][2];
    
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 1;
    
    cin >> n;
    
    for(int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i - 2][0] + dp[i - 1][0]) % 15746;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 15746;
    }
    
    cout << (dp[n][0] + dp[n][1]) % 15746;

    return 0;
}
