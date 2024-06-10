#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > s;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    
    cin >> N >> K;
    
    int M, V;
    for(int i = 0; i < N; i++) {
        cin >> M >> V;
        s.push_back({V, M});
    }
     sort(s.begin(), s.end());
    
    int w;
    for(int i = 0; i < K; i++) {
        cin >> w;
        bag.insert(w);
    }
    
    //가격 높은 보석을 무게 낮은 가방에 넣는다.
    multiset<int>::iterator it;
    long long ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        it = bag.lower_bound(s[i].second);
        if(it == bag.end()) {
            continue;
        }
        bag.erase(it);
        ans += s[i].first;
    }
    
    cout << ans << "\n";

    return 0;
}
