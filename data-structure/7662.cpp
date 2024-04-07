#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, k;
    
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> k;
        multiset<int> s;
        for(int j = 0; j < k; j++) {
            char c;
            int v;
            cin >> c >> v;
            if(c == 'I') {
                s.insert(v);
            }else {
                if(!s.empty()) {
                    if(v == 1) {
                        s.erase(prev(s.end())); //최대값
                    }else {
                        s.erase(s.begin()); //최소값
                    }
                }
            }
        }
        if(s.empty()) {
            cout << "EMPTY\n";
        }else {
            cout << *(prev(s.end())) << " " << *(s.begin()) << "\n";
        }
    }
    
    return 0;
}
