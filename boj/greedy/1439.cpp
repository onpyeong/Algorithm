#include <iostream>

using namespace std;

int cnt[2];

int main()
{
    string s;
    cin >> s;
    
    int i = 0;
    while(i < s.size()) {
        char c = s[i];
        while(s[i] == c){
            i++;
        }
        cnt[c - '0']++;
    }
    
    cout << min(cnt[0], cnt[1]);
    return 0;
}
