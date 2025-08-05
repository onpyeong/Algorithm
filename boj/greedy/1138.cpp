#include <iostream>

using namespace std;

int N;
int a[11];

int main() {
    int t, cnt;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
      cin >> t;
      cnt = 0;
      int k;
      for(int j = 0; j < N; j++) {
        if(a[j] == 0)
          cnt++;
        if(cnt == t + 1) {
          k = j;
          while(a[k] != 0)
            k++;
          break;
        }
      }
      a[k] = i + 1; 
    }
    
    for(int i = 0; i < N; i++)
      cout << a[i] << " ";
    return 0;
}
