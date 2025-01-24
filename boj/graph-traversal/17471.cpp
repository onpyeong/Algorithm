#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, answer = 10000;
int people[15];
bool group[15];
bool visit[15];
vector<int> adj[15];

int checkConnectArea(bool groupNum, int areaCount);

void divideGroup() {
  int first, second, areaCount;
  for(int i = 1; i < pow(2, N - 1); i++) { //지역 선택
    areaCount = 0;
    for(int j = 0; j < N; j++) {
      if(i & (1 << j)) {
        group[j + 1] = true;
        areaCount++;
      }else {
        group[j + 1] = false;
      }
    }
    
    first = checkConnectArea(true, areaCount); 
    second = checkConnectArea(false, N - areaCount);
    if(!first || !second) //둘 중 하나라도 연결되어 있지 않으면
      continue;
    answer = min(abs(first - second), answer);  //인구 수 계산해서 answer에 갱신
  }
}

int checkConnectArea(bool groupNum, int areaCount) { //groupNum 그룹 연결 확인 -> 인구 수 계산
  int x, visitAreaCount = 0, totalPeople = 0;
  int startPoint;
  queue<int> q;
  
  for(int i = 1; i <= N; i++) {
    if(group[i] == groupNum) {
      startPoint = i;
    }
    visit[i] = false;
  }

  q.push(startPoint);
  visit[startPoint] = true;
  totalPeople = people[startPoint];
  while(!q.empty()) {
    x = q.front();
    q.pop();
    visitAreaCount++;
    if(areaCount == visitAreaCount) { //지역 다 방문했으면
      break;
    }
    for(int nx : adj[x]) {
      if(visit[nx] || group[nx] != groupNum)
        continue;
      totalPeople += people[nx];
      q.push(nx);
      visit[nx] = true;
    }
  }
  
  if(areaCount > visitAreaCount) //연결되지 않은 경우
    totalPeople = 0;

  return totalPeople;
}


int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int adjCnt, adjNum;
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> people[i];
    }
    
    for(int i = 1; i <= N; i++) {
      cin >> adjCnt;
      for(int j = 0; j < adjCnt; j++) {
        cin >> adjNum;
        adj[i].push_back(adjNum);
        adj[adjNum].push_back(i);
      }
    }
    
    divideGroup();
    if(answer == 10000)
      answer = -1;
    
    cout << answer << "\n";
    
    return 0;
}
