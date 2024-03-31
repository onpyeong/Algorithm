#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int x;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> x;
        b.push_back(x);
    }
    
    sort(b.begin(), b.end());
    
    for(int i = 0; i < n; i++) {
        if(!binary_search(b.begin(), b.end(), a[i]))
            ans.push_back(a[i]);
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
