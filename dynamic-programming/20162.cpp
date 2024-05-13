#include <iostream>
#include <algorithm>

using namespace std;

int score[1005];
int dp[1005];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> score[i];
        dp[i] = score[i]; //자신보다 작은 점수가 없는 경우
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(score[j] < score[i]) {
                dp[i] = max(dp[i], dp[j] + score[i]);
            }
        }
    }
    
    cout << *max_element(dp, dp + N) << "\n";
    return 0;
}
