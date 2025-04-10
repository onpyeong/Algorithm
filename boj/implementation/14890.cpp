#include <iostream>

using namespace std;

int N, L;
int map[101][101];
int score;
     
bool checkRow(int r) {
    int len = 1;
    int pivot = map[r][0];
    bool wasDown = false;
    for(int c = 1; c < N; c++) {
        if(map[r][c] == pivot) {
            len++;
            if(wasDown && len == L) {
                len = 0;
                wasDown = false;
            }
        }else if(map[r][c] + 1 == pivot) { 
            if(wasDown && len < L) {
                return false;
            }
            wasDown = true;
            len = 1;
            pivot = map[r][c];
            if(len == L) {
                len = 0;
                wasDown = false;
            }
        }else if(map[r][c] == pivot + 1){ //올라간 경우
            if(len < L) {
                return false;
            }
            wasDown = false;
            len = 1;
            pivot = map[r][c];
        }else {
            return false;
        }
    }
    if(wasDown && len < L)
        return false;
    return true;
}
     
static bool checkCol(int c) {
    int len = 1;
    int pivot = map[0][c];
    bool wasDown = false;
    for(int r = 1; r < N; r++) {
        if(map[r][c] == pivot) {
            len++;
            if(wasDown && len == L) {
                len = 0;
                wasDown = false;
            }
        }else if(map[r][c] + 1 == pivot) { 
            if(wasDown && len < L) {
                return false;
            }
            wasDown = true;
            len = 1;
            pivot = map[r][c];
            if(len == L) {
                len = 0;
                wasDown = false;
            }
        }else if(map[r][c] == pivot + 1){ //올라간 경우
            if(len < L) {
                return false;
            }
            wasDown = false;
            len = 1;
            pivot = map[r][c];
        }else {
            return false;
        }
    }
    if(wasDown && len < L)
        return false;
    return true;
}
     
int main() {
  cin >> N >> L;
  for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
          cin >> map[i][j];
      }
  }
   
  for(int i = 0; i < N; i++) {
      if(checkRow(i)) {
          score++;
      }
      if(checkCol(i)) {
          score++;
      }
  }

  cout << score << "\n";
  return 0;
}
