#include <iostream>

using namespace std;

int dp[100001];

int main() {
    int N, t;
    int ans = 0;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        dp[i] = i; //1로만 더한 경우로 초기화
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1); //제곱수를 제외하고 남은 최소 항의 개수
        }
    }
    
    cout << dp[N];

    return 0;
}
