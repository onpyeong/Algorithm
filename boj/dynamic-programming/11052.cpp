#include <iostream>

using namespace std;

int N;
int p[10001];
int dp[1001];

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    
    dp[1] = p[1];
    for(int k = 2; k <= N; k++) {
        dp[k] = p[k];
        for(int i = 1; i <= k - i; i++) {
            dp[k] = max(dp[k], dp[k - i] + p[i]);
        }
    }
    cout << dp[N];

    return 0;
}
