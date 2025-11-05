#include <iostream>
#include <queue>

using namespace std;

int T;
bool visit[10001];
int A, B;

string bfs() {
  fill(visit, visit + 10001, 0);
  queue<pair<int, string>> q;
  int x, t;
  string inst;
  
  q.push({A, ""});
  visit[A] = true;
  while(!q.empty()) {
    x = q.front().first;
    inst = q.front().second;
    q.pop();
    
    if(x == B)
      return inst;
    
    t = x * 2 % 10000;
    if(!visit[t]) {
      q.push({t, inst + 'D'});
      visit[t] = inst.size() + 1;
    }
    t = (x == 0? 9999 : x - 1);
    if(!visit[t]) {
      q.push({t, inst + 'S'});
      visit[t] = inst.size() + 1;
    }
    t = x % 1000 * 10 + x / 1000;
    if(!visit[t]) {
      q.push({t, inst + 'L'});
      visit[t] = inst.size() + 1;
    }
    t = x % 10 * 1000 + x / 10;
    if(!visit[t]) {
      q.push({t, inst + 'R'});
      visit[t] = inst.size() + 1;
    }
  }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      cin >> A >> B;
      cout << bfs() << '\n';
    }
    return 0;
}
