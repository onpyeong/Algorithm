#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, x;
    long long ans = 0;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x;
        pq.push(x);
    }
    
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        //if(!pq.empty()) -> 비어있을 때 넣어도 다음 반복문에서 탈출
            pq.push(a + b);
    }
    
    cout << ans << "\n";

    return 0;
}
