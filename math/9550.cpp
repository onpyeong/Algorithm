#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, K;
    
    cin >> T;
    
    int cnt, ans;
    for(int i = 0; i < T; i++) {
        cin >> N >> K;
        ans = 0;
        for(int j = 0; j < N; j++) {
            cin >> cnt; 
            ans += (cnt / K);
        }
        cout << ans << "\n";
    }

    return 0;
}
