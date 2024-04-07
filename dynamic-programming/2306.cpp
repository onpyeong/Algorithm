#include <iostream>
#include <cmath>

using namespace std;

int dp[505][505];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    
    for(int size = 1; size < len; size++) { //작은 단위 케이스 -> 길이 2부터 늘리면서 확인
        for(int st = 0; st + size < len; st++) {
            int ed = st + size;

            //양 끝 확인
            if(s[st] == 'a' && s[ed] == 't' || s[st] == 'g' && s[ed] == 'c'){
                dp[st][ed] = dp[st + 1][ed - 1] + 2;
            }
            
            //합하면 유전자
            for(int mid = st; mid < ed; mid++) {
                dp[st][ed] = max(dp[st][ed], dp[st][mid] + dp[mid + 1][ed]);
            }
        }
    }
    
    cout << dp[0][len - 1];

    return 0;
}
