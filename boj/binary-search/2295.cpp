#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[1001];
vector<int> two;

bool binary_search(int k) {
    int s = 0;
    int e = two.size();
    while(s < e) {
        int mid = (s + e) / 2;
        if(two[mid] < k) {
            s = mid + 1;
        }else if(two[mid] > k) {
            e = mid - 1;
        }else {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    for(int x = 0; x < n; x++) {
        for(int y = x; y < n; y++) {
            two.push_back(a[x] + a[y]);
        }
    }
    sort(two.begin(), two.end());
    
    //k - z가 two에 있는지 이분 탐색
    for(int k = n - 1; k >= 0; k--) {
        for(int z = k - 1; z >= 0; z--) {
            if(binary_search(a[k] - a[z])) {
                cout << a[k];
                return 0;
            }
        }
    }
}
