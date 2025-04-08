#include <iostream>
#define WALL 2
#define TRAP 1
using namespace std;

int L, N, Q;
int map[42][42]; //덫, 벽 저장
int dmap[42][42]; //기사 저장
struct Knight {
    int r;
    int c;
    int h;
    int w;
    int k; //최초 체력
    int d;
    int curk; //현재 체력
    bool isDelete;
};
Knight knights[31];
int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 상 우 하 좌

bool canPush(int num, int dir) {
    int sx = knights[num].r, sy = knights[num].c;
    int ex = sx + knights[num].h - 1, ey = sy + knights[num].w - 1;
    if(dir == 0) {
      for (int y = sy; y <= ey; y++) {
        if (map[sx - 1][y] == WALL) {
            return false;
        }
        if (dmap[sx - 1][y] != 0) {
            if (!canPush(dmap[sx - 1][y], dir))
                return false;
        }
      }
    }else if(dir == 1) {
      for (int x = sx; x <= ex; x++) {
        if (map[x][ey + 1] == WALL) {
            return false;
        }
        if (dmap[x][ey + 1] != 0) {
            if (!canPush(dmap[x][ey + 1], dir))
                return false;
        }
      }
    }else if(dir == 2) {
      for (int y = sy; y <= ey; y++) {
        if (map[ex + 1][y] == WALL) {
            return false;
        }
        if (dmap[ex + 1][y] != 0) {
            if (!canPush(dmap[ex + 1][y], dir))
                return false;
        }
      }
    }else {
      for (int x = sx; x <= ex; x++) {
        if (map[x][sy - 1] == WALL) {
            return false;
        }
        if (dmap[x][sy - 1] != 0) {
            if (!canPush(dmap[x][sy - 1], dir))
                return false;
        }
      }
    }
    return true;
}

void deleteKnight(int num) {
  int r = knights[num].r;
  int c = knights[num].c;
  int h = knights[num].h;
  int w = knights[num].w;
  for (int x = 0; x < h; x++) {
      for (int y = 0; y < w; y++) {
          dmap[r + x][c + y] = 0;
      }
  }
  knights[num].isDelete = true;
}

void push(int num, int dir, bool damage) {
    int sx = knights[num].r, sy = knights[num].c;
    int ex = sx + knights[num].h - 1, ey = sy + knights[num].w - 1;
    if(dir == 0) {
      for (int y = sy; y <= ey; y++) {
        if (dmap[sx - 1][y] != 0) {
            push(dmap[sx - 1][y], dir, damage);
        }
      }
      for (int y = sy; y <= ey; y++) {
          dmap[sx - 1][y] = dmap[sx][y];
          if(map[sx - 1][y] == 1)
            knights[num].d++;
          dmap[ex][y] = 0;
          if(map[ex][y] == 1)
            knights[num].d--;
      }
      knights[num].r = sx - 1;
    }else if(dir == 1) {
      for (int x = sx; x <= ex; x++) {
        if (dmap[x][ey + 1] != 0) {
            push(dmap[x][ey + 1], dir, damage);
          }
      }
      for (int x = sx; x <= ex; x++) {
          dmap[x][ey + 1] = dmap[x][ey];
          if(map[x][ey + 1] == 1)
            knights[num].d++;
          dmap[x][sy] = 0;
          if(map[x][sy] == 1)
            knights[num].d--;
      }
      knights[num].c = sy + 1;
    }else if(dir == 2) {
      for (int y = sy; y <= ey; y++) {
        if (dmap[ex + 1][y] != 0) {
            push(dmap[ex + 1][y], dir, damage);
        }
      }
      for (int y = sy; y <= ey; y++) {
          dmap[ex + 1][y] = dmap[ex][y];
          if(map[ex + 1][y] == 1)
            knights[num].d++;
          dmap[sx][y] = 0;
          if(map[sx][y] == 1)
            knights[num].d--;
      }
      knights[num].r = sx + 1;
    }else {
      for (int x = sx; x <= ex; x++) {
        if (dmap[x][sy - 1] != 0) {
            push(dmap[x][sy - 1], dir, damage);
          }
      }
      for (int x = sx; x <= ex; x++) {
          dmap[x][sy - 1] = dmap[x][sy];
          if(map[x][sy - 1] == 1)
            knights[num].d++;
          dmap[x][ey] = 0;
          if(map[x][ey] == 1)
            knights[num].d--;
      }
      knights[num].c = sy - 1;
    }
    if(damage) {
      knights[num].curk -= knights[num].d;
      if(knights[num].curk <= 0) {
        deleteKnight(num);
      }
    }
}

void moveKnight(int num, int dir) {
    int sx = knights[num].r, sy = knights[num].c;
    int ex = sx + knights[num].h - 1, ey = sy + knights[num].w - 1;
    if(dir == 0) { //상
      for (int y = sy; y <= ey; y++) {
          if (map[sx - 1][y] == WALL) {
              return;
          }
          if (dmap[sx - 1][y] != 0) {
              if (!canPush(dmap[sx - 1][y], dir)) 
                return;
          }
      }
      for (int y = sy; y <= ey; y++) {
          if (dmap[sx - 1][y] != 0) {
              push(dmap[sx - 1][y], dir, true);
          }
      }
    }else if (dir == 1) { //우
        for (int x = sx; x <= ex; x++) {
            if (map[x][ey + 1] == WALL) {
                return;
            }
            if (dmap[x][ey + 1] != 0) {
                if (!canPush(dmap[x][ey + 1], dir))
                    return;
            }
        }
        for (int x = sx; x <= ex; x++) {
            if (dmap[x][ey + 1] != 0) {
                push(dmap[x][ey + 1], dir, true);
            }
        }
    }else if (dir == 2) { //하
     for (int y = sy; y <= ey; y++) {
          if (map[ex + 1][y] == WALL) {
              return;
          }
          if (dmap[ex + 1][y] != 0) {
              if (!canPush(dmap[ex + 1][y], dir))
                  return;
          }
      }
      for (int y = sy; y <= ey; y++) {
          if (dmap[ex + 1][y] != 0) {
              push(dmap[ex + 1][y], dir, true);
          }
      }
    }else {
     for (int x = sx; x <= ex; x++) {
            if (map[x][sy - 1] == WALL) {
                return;
            }
            if (dmap[x][sy - 1] != 0) {
                if (!canPush(dmap[x][sy - 1], dir))
                    return;
            }
        }
        for (int x = sx; x <= ex; x++) {
            if (dmap[x][sy - 1] != 0) {
                push(dmap[x][sy - 1], dir, true);
            }
        }
    }
    push(num, dir, false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, h, w, k;
    int num, dir;

    cin >> L >> N >> Q;
    for (int i = 0; i <= L + 1; i++) {
        map[0][i] = WALL;
        map[L + 1][i] = WALL;
    }
    for (int i = 1; i <= L; i++) {
        map[i][0] = WALL;
        map[i][L + 1] = WALL;
        for (int j = 1; j <= L; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> r >> c >> h >> w >> k;
        knights[i] = { r, c, h, w, k, 0, k, false };
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                dmap[r + x][c + y] = i;
                if(map[r + x][c + y] == 1) {
                  knights[i].d++;
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cin >> num >> dir;
        if (knights[num].isDelete) {
            continue;
        }
        moveKnight(num, dir);
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i++) {
      if(!knights[i].isDelete) {
        answer += knights[i].k - knights[i].curk;
      }
    }
    cout << answer << "\n";
    
    return 0;
}
