#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

string s, t;
int N;
set<string> s_set;
bool dp[101]; // dp[i]: s[0..i-1]까지 만들 수 있는가?

// Top-down
// bool f2(int si, int ei) { //시작 인덱스, 길이
//   if(dp[si][ei] == 1)
//     return true;
//   if(dp[si][ei] == -1)
//     return false;
//  //dp값이 없으면 직접 찾아보고 true로 만들어주기 
//  if(s_set.find(s.substr(si, ei)) != s_set.end()) {
//     dp[si][ei] = 1;
//     return true;
//   }
//   for(int i = 1; i < ei; i++) { //짧은 길이부터
//     if(f2(si, i) && f2(si + i, ei - i)) { //쪼개서 둘다 true이면 true
//       dp[si][ei] = 1;
//       return true;
//     }
//   }
//   dp[si][ei] = -1;
//   return false;
// }

int main() {
  cin >> s;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> t;
    s_set.insert(t);
  }
  int s_size = s.size();

  //Bottom-up
  dp[0] = true; // 빈 문자열은 만들 수 있음

  for(int i = 1; i <= s_size; i++) { //가장 길이가 짧은 문자열부터 만들어봄
    for(int j = 0; j < i; j++) { //길이[j]가 가능하고, j 이후 문자열이 있다면? 길이 i도 가능
      if(dp[j] && s_set.find(s.substr(j, i - j)) != s_set.end()) {
        dp[i] = true;
        break;
      }
    }
  }

  cout << dp[s_size] << "\n";

  return 0;
}
