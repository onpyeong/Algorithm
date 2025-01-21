#include <iostream>
#include <queue>
using namespace std;

int A, B, N, M, answer;
queue<pair<int, int>> q;
bool visit[100005];

void isValidPlusIdx(int i, int x, int cnt) {
  if((x < 0 && i + x >= 0) || (x >= 0 && i + x <= 100000)) {
    if(!visit[i + x]) {
      q.push({i + x, cnt});
      visit[i + x] = true;
    }
  }
}

void isValidMultiIdx(int i, int x, int cnt) {
  if(i * x <= 100000) {
    if(!visit[i * x]) {
      q.push({i * x, cnt});
      visit[i * x] = true;
    }
  }
}

int BFS() {
  int x, cnt;
  
  q.push({N, 0});
  visit[N] = true;
  while(!q.empty()) {
    x = q.front().first;
    cnt = q.front().second;
    q.pop();
    if(x == M) {
      return cnt;
    }
    isValidPlusIdx(x, -1, cnt + 1);
    isValidPlusIdx(x, 1, cnt + 1);
    isValidPlusIdx(x, -A, cnt + 1);
    isValidPlusIdx(x, A, cnt + 1);
    isValidPlusIdx(x, -B, cnt + 1);
    isValidPlusIdx(x, B, cnt + 1);
    isValidMultiIdx(x, A, cnt + 1);
    isValidMultiIdx(x, B, cnt + 1);
  }
}


int main() 
{
    cin >> A >> B >> N >> M;
    cout << BFS() << "\n";
    return 0;
}
