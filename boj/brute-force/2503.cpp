#include <iostream>

using namespace std;

int N;
int questions[101][3]; // 자릿수로 저장
pair<int, int> answers[101]; // s, b
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int question, s, b;
    int j;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> question >> s >> b;
      j = 2;
      while(question > 0) {
        questions[i][j--] = question % 10;
        question /= 10;
      }
      answers[i] = {s, b};
    }
    
    bool isPoss;
    for(int i = 1; i <= 9; i++) {
      for(int j = 1; j <= 9; j++) {
        if(i == j) {
          continue;
        }
        for(int k = 1; k <= 9; k++) {
          if(i == k || j == k) {
            continue;
          }
          isPoss = true;
          for(int q = 0; q < N; q++) {
            s = b = 0;
            if(i == questions[q][0]) {
              s++;
            }else if(i == questions[q][1] || i == questions[q][2]) {
              b++;
            }
            if(j == questions[q][1]) {
              s++;
            }else if(j == questions[q][0] || j == questions[q][2]) {
              b++;
            }
            if(k == questions[q][2]) {
              s++;
            }else if(k == questions[q][0] || k == questions[q][1]) {
              b++;
            }
            if(s != answers[q].first || b != answers[q].second) {
              isPoss = false;
              break;
            }
          }
          if(isPoss) {
            cnt++;
          }
        }
      }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
