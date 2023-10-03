#define MAX 10001
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int dp[MAX];
    int wine[MAX];
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = max(wine[1], wine[2])  + wine[3];
    
    for(int i = 4; i <= n; i++) {
        dp[i] = max(max(wine[i - 1] + dp[i - 3], dp[i - 2]), wine[i - 1] + dp[i - 4]) + wine[i];
    }
    
    cout << max(dp[n], dp[n - 1]);

    return 0;
}
