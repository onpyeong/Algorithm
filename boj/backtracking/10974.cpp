#include <iostream>

using namespace std;

int N;
int a[8];
bool is_used[8];

void backtracking(int k) {
  if(k == N) {
    for(int i = 0; i < N; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i = 0; i < N; i++) {
    if(!is_used[i]) {
      a[k] = i + 1;
      is_used[i] = true;
      backtracking(k + 1);
      is_used[i] = false;
    }
  }
}

int main() {
    cin >> N;
    
    backtracking(0);
    
    return 0;
}
