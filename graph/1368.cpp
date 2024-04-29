#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

vector<int> p(305, -1);
vector<tuple<int, int, int>> edge;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(a < b) p[b] = a;
    else p[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int w;
        cin >> w;
        edge.push_back({w, 0, i});
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int w;
            cin >> w;
            if(i < j)
                edge.push_back({w, i, j});
        }
    }
    sort(edge.begin(), edge.end());
    
    int ans = 0, cnt = 0;
    for(int i = 0; i < edge.size(); i++) {
        int w, a, b;
        tie(w, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += w;
        cnt++;
        if(cnt == N) break;
    }
    
    cout << ans;

    return 0;
}
