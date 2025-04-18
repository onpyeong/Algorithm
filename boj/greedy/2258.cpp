#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> v;
bool compare(pair<int, int> &a, pair<int, int> &b) {
  if(a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, c;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
      cin >> w >> c;
      v.push_back({w, c});
    }
    
    sort(v.begin(), v.end(), compare); //가격 순으로 정렬 -> 무게는 큰 순으로 
    
    long long sum_w = v[0].first;
    long long sum_c = v[0].second;
    int i;
    long long answer = LLONG_MAX;
    for(i = 1; i < N; i++) {
      if(M <= sum_w) {
        answer = min(sum_c, answer); //정답 갱신
      }
      sum_w += v[i].first; //가격이 커지면, 그 앞 무게들을 전부 얻을 수 있음
      if(v[i].second > v[i - 1].second) { //가격이 바뀌는 구간이면
        sum_c = v[i].second; //가격 변경
      }else { //가격이 같으면
        sum_c += v[i].second; //가격 누적
      }
      
    }
    if(M <= sum_w) { //정답 갱신
      answer = min(sum_c, answer);
    }
    if(answer != LLONG_MAX) {
      cout << answer << "\n";
    }else {
      cout << -1 << "\n";
    }

    return 0;
}
