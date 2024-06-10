#include <iostream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 1;
    
    int sLen = s.size(), tLen = t.size();
    int maxLen = sLen * tLen;
    int i = 0, j = 0, x = 0;
    while(x < maxLen) {
        if(s[i] != t[j]) {
            ans = 0;
            break;
        }
        i++; j++;
        if(i == sLen) {
            i = 0;
        }
        if(j == tLen) {
            j = 0;
        }
        x++;
    }

    cout << ans;
    
    return 0;
}
