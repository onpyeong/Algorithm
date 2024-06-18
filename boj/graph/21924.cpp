#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100005];
vector<pair<int, pair<int, int>>> e; //비용, 간선

int find_parent(int x) {
    if(p[x] != x)
        p[x] = find_parent(p[x]);
    return p[x];
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    int N, M;
    long long total = 0, min_c = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        p[i] = i;
    }
    
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        total += c;
        e.push_back({c, {a, b}});
    }
    
    sort(e.begin(), e.end());
    
    for(int i = 0; i < e.size(); i++) {
        int c = e[i].first;
        int a = e[i].second.first;
        int b = e[i].second.second;
        if(find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            min_c += c;
        }
    }
    
    bool flag = true;
    for(int i = 2; i <= N; i++) {
        if(find_parent(1) != find_parent(i)) {
            flag = false;
        }
    }
    cout << (flag ? total - min_c : -1);

    return 0;
}
