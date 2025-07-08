#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int len[10003];

void print_min_score() {
  int score = len[1] - len[0];
  for(int i = 0; i + 2 < N; i++) {
    score = max(score, len[i + 2] - len[i]);
  }
  score = max(score, len[N - 1] - len[N - 2]);
  cout << score << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      cin >> N;
      for(int j = 0; j < N; j++) {
        cin >> len[j];
      }
      sort(len, len + N);
      print_min_score();
    }
    return 0;
}
