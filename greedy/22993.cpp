#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    bool isWin = true;
    cin >> N;
    
    long long a;
    cin >> a;
    for(int i = 1; i < N; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    
    for(int t : v) {
        if(a > t) {
            a += t;
        }else {
            isWin = false;
            break;
        }
    }
    
    if(isWin)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
