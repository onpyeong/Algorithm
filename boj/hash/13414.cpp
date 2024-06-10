#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<string, int> m;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, L;
    
    cin >> K >> L;
    
    string x;
    for(int i = 0; i < L; i++) {
        cin >> x;
        m[x] = i;
    }
    
    vector <pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < K; i++) {
        if(i == v.size()) break;
        cout << v[i].first << "\n";
    }

    return 0;
}
