#include <iostream>

using namespace std;

int a[2001];
int dp[2001];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        for(int j = n - 1; j > i; j--) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int answer = -1;
    for(int i = 0; i < n; i++) {
        answer = max(answer, dp[i]);
    }
    cout << n - answer << "\n";
    
    return 0;
}
