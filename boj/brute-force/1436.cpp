#include <iostream>

using namespace std;

int N;

int main() {
    int cnt = 0;
    int num = 665;
    string t;
    
    cin >> N;
    
    while(true) {
      num++;
      t = to_string(num);
      for(int i = 0; i < t.size() - 2; i++) {
        if(t[i] == '6' && t[i + 1] == '6' && t[i + 2] == '6') {
          cnt++;
          break;
        }
      }
      if(cnt == N) {
        cout << t;
        break;
      }
    }
    
    return 0;
}
