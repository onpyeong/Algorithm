#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, M;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, cnt = 0;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            cin >> n;
            q.push({n, i});
            pq.push(n);
        }
        while(!q.empty()) {
            int p = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(p < pq.top()) { //자신보다 중요도가 높은 숫자가 있는지 확인
                q.push({p, idx});
            }else {
                cnt++;
                pq.pop();
                if(idx == M) {
                    cout << cnt << "\n";
                    break;
                }
            }
        }
        while(!q.empty()) {
            q.pop();
        }
        while(!pq.empty()) {
            pq.pop();
        }
    }

    return 0;
}
