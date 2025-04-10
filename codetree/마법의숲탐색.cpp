#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R, C, K;
int forest[75][75];
bool visit[75][75];
int answer;
int dx[] = { -1, 0, 1, 0}; // 북 동 남 서
int dy[] = { 0, 1, 0, -1};
int golems[1003][2]; //중앙
int e[1003]; //출구

//체크해야 하는 좌표
int addDir[3][5][2] = {
  {{-1, 1}, {0, 2}, {1, 1}, {1, 2}, {2, 1}}, //동
  {{1, -1}, {2, 0}, {1, 1}}, //남
  {{-1, -1}, {0, -2}, {1, -1}, {1, -2}, {2, -1}} //서
};

bool move(int num, int dir) {
    int cx = golems[num][0];
    int cy = golems[num][1];
    int cDir, nx, ny;
    int count = 0;
    bool moveDown = false;
    bool isStop = false;
    int dSize;

    while (true) {
        dSize = (dir == 2)? 3 : 5;
        for (int i = 0; i < dSize; i++) { 
            nx = cx + addDir[dir - 1][i][0];
            ny = cy + addDir[dir - 1][i][1];
            if (nx > R + 3 || ny < 1 || ny > C) { //범위를 벗어나면
                isStop = true;
                break;
            }     
            if (forest[nx][ny] != 0) { //막혀있으면
              isStop = true;
              break;
            }
        }
        if(isStop)
          break;
        for (int j = 0; j < 4; j++) {
            forest[cx + dx[j]][cy + dy[j]] = 0;
        }
        golems[num][0] += dx[dir];
        golems[num][1] += dy[dir];
        cx = golems[num][0];
        cy = golems[num][1];
        forest[cx][cy] = num;
        for (int j = 0; j < 4; j++) {
            forest[cx + dx[j]][cy + dy[j]] = num;
        }
        if(dir == 2) {
          moveDown = true;
        }
        count++;
        if ((dir == 3 || dir == 1) && count == 1) { //딱 1번 동, 서로 이동한 후 남으로 바꿔줌
            if (dir == 3) { //서
                //출구를 반시계로 회전
                e[num] = (e[num] + 3) % 4;
            }else { //동
                //출구를 시계로 회전
                e[num] = (e[num] + 1) % 4;
            }
            dir = 2;
        }
    }
    if(!moveDown) // 한 칸이라도 아래로 이동하지 않았다면
      return false;
    return true;
    
}

int moveFairy(int num) {
    queue<pair<int, int>> q;
    memset(visit, 0, sizeof(visit));
    int x, y, nx, ny;
    int maxX = -1;

    q.push({ golems[num][0] + dx[e[num]], golems[num][1] + dy[e[num]] });
    visit[golems[num][0] + dx[e[num]]][golems[num][1] + dy[e[num]]] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x > maxX) {
            maxX = x;
        }
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (ny < 1 || ny > C || nx < 1 || nx > R + 3)
                continue;
            if (visit[nx][ny] || forest[nx][ny] == 0) 
                continue;
            if(x == golems[forest[x][y]][0] + dx[e[forest[x][y]]]
            && y == golems[forest[x][y]][1] + dy[e[forest[x][y]]]) { //출구
              q.push({ nx, ny });
              visit[nx][ny] = true;
            }else if(forest[nx][ny] == forest[x][y] ||
            (nx == golems[forest[x][y]][0] + dx[e[forest[x][y]]]
            && ny == golems[forest[x][y]][1] + dy[e[forest[x][y]]])) {
              //같은 골렘의 몸체이거나, 나의 출구이면
              q.push({ nx, ny });
              visit[nx][ny] = true;
            }
        }
    }
    return maxX - 3; //위에 3줄을 빼줌
}


void searchForest(int num) {
    //남 -> 서 -> 동 어디로도 이동 못할 경우 stop
    while (move(num, 2) || move(num, 3) || move(num, 1)) {
    }
    if(golems[num][0] >= 5) { //범위 내에 있으면 (위에 3줄 제외)
      answer += moveFairy(num); 
    }else { //범위 바깥이면 전부 삭제
        memset(forest, 0, sizeof(forest));
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> R >> C >> K;
    for (int i = 1; i <= K; i++) {
        cin >> c >> e[i]; //c열 d위치에서 내려옴
        golems[i][0] = 2; //중앙 x 좌표
        golems[i][1] = c; //중앙 y 좌표
        forest[2][c] = i; //위치 시키기
        for (int j = 0; j < 4; j++) {
            forest[2 + dx[j]][c + dy[j]] = i;
        }
        searchForest(i);
    }
    cout << answer << "\n";

    return 0;
}
