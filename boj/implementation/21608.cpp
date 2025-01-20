#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, total, tmp, answer;
vector<int> likeFriend[405]; //좋아하는 친구
int order[405]; // 학생의 순서
int desk[21][21]; //좌석
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Cell{
  int x, y;
  int friends;
  int empty;
};

bool compare(const Cell &a, const Cell &b) {
  if(a.friends == b.friends) {
    if(a.empty == b.empty) {
      if(a.x == b.x) {
        return a.y < b.y;
      }
      return a.x < b.x;
    }
    return a.empty > b.empty;
  }
  return a.friends > b.friends;
}

void findDesk(int num) {
  int nx, ny;
  int friends, empty;
  vector<Cell> cells;
  for(int x = 0; x < N; x++) {
    for(int y = 0; y < N; y++) {
      if(desk[x][y] != 0)
        continue;
      friends = empty = 0;
      for(int d = 0; d < 4; d++) {
        nx = x + dx[d];
        ny = y + dy[d];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;
        if(desk[nx][ny] == 0)
          empty++;
        else {
          for(int f : likeFriend[num]) {
            if(f == desk[nx][ny])
              friends++;
          }
        }
      }
      cells.push_back({x, y, friends, empty});
    }
  }
  
  sort(cells.begin(), cells.end(), compare);
  
  Cell c = cells[0];
  desk[c.x][c.y] = num;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  cin >> N;
  total = N * N;
  for(int i = 0; i < total; i++) {
    cin >> order[i];
    for(int j = 0; j < 4; j++) {
      cin >> tmp;
      likeFriend[order[i]].push_back(tmp);
    }
  }
  
  for(int i = 0; i < total; i++) {
    findDesk(order[i]);
  }
  
  int nx, ny, friends;
  for(int x = 0; x < N; x++) {
    for(int y = 0; y < N; y++) {
      friends = 0;
      for(int d = 0; d < 4; d++) {
        nx = x + dx[d];
        ny = y + dy[d];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;
        for(int f : likeFriend[desk[x][y]]) {
          if(f == desk[nx][ny])
            friends++;
        }
      }
      if(friends == 0)
        continue;
      answer += pow(10, friends - 1);
    }
  }

  cout << answer << "\n";
}
