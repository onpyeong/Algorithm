#include <iostream>

using namespace std;

int num[11];

int main() {
    string s;
    int n, ans = 0;
    
    cin >> s;
    for(char c : s) {
      n = c - '0';
      num[n]++;
    }
    
    if(num[6] >= num[9]) {
      int diff = num[6] - num[9];
      num[6] -= diff / 2;
      num[9] += diff / 2;
    }else {
       int diff = num[9] - num[6];
      num[9] -= diff / 2;
      num[6] += diff / 2;
    }
    
    for(int i = 0; i <= 9; i++) {
      ans = max(num[i], ans);      
    }
    
    cout << ans;
    return 0;
}
