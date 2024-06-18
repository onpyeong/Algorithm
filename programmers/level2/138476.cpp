#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[10000005];

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int t : tangerine) {
        cnt[t]++;
    }
    sort(cnt, cnt + 10000005, greater<int>());
    for(int i = 0; i < 10000005; i++) {
        if(k <= 0)
            break;
        answer++;
        k -= cnt[i];
    }
    return answer;
}
