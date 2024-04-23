#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p(10005, -1);

int find(int x) { 
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false; //부모가 같으면 같은 그룹
    //부모 갱신
    if(a < b) p[b] = a;
    else p[a] = b;
    return true;
}

tuple<int, int, int> edge[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    int ans = 0;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int cost, a, b;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    
    sort(edge, edge + e);
    
    int cnt = 0;
    //낮은 간선부터 하나씩 선택하기
    for(int i = 0; i < e; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue; //같은 그룹의 정점이면 pass
        ans += cost;
        cnt++;
        if(cnt == v - 1) break;
    }
    
    cout << ans;

    return 0;
}
