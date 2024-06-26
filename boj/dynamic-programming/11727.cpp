#include <iostream>

using namespace std;

int dp[1005];

int main() {
    int N;
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    }
    
    cout << dp[N];

    return 0;
}
