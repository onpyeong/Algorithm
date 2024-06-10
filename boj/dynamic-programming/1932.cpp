#include <iostream>
#include <algorithm>

using namespace std;

int dp[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int idx = 1;
    cin >> dp[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            idx++;
            int t;
            cin >> t;
            if(j == 1)
                dp[idx] = dp[idx - (i - 1)] + t;
            else if(j == i)
                dp[idx] = dp[idx - j] + t;
            else
                dp[idx] = max(dp[idx - i], dp[idx - i + 1]) + t; 
        }
    }
    
    cout << *max_element(dp, dp + idx + 1);

    return 0;
}
