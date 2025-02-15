#include <iostream>
#include <queue>

using namespace std;

int n;
int map[25][25];
int candidateNum[55559];
int structure[6];
int sz;

void makeStructure(int k);
void calcTotalCandidate();
int numberOfCandidate(int M, int mStructure[5]);
void copyMap();
int calcArea(int seaLevel);

int temp[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init(int N, int mMap[20][20])
{
    n = N;
    for(int i = 0; i < n + 2; i++) {
        for(int j = 0; j < n + 2; j++) {
            if(i == 0 || i == n + 1 || j == 0 || j == n + 1)
                map[i][j] = 0;
            else
                map[i][j] = mMap[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= 5; i++) {
        sz = i;
        makeStructure(0);
    }
}

void makeStructure(int k) {
    if(k == sz) {
        calcTotalCandidate();
        return;
    }
    for(int i = 1; i <= 5; i++) {
        structure[k] = i;
        makeStructure(k + 1);
    }
}

bool isSame() {
    bool same = true;
    for(int i = 0; i < sz; i++) {
        if(structure[i] != structure[sz - 1 - i]) {
            same = false;
        }
    }
    return same;
}

int makeHash() {
    int t = structure[0];
    for(int i = 1; i < sz; i++) {
        t = t * 10 + structure[i];
    }
    return t;
}

void calcTotalCandidate() {
    //모든 조합에 대해 경우의 수 전부 계산하고 숫자만 저장
    int t = makeHash();

    if(sz == 1) { //구조물 크기 1이면 전체 배열 크기
        candidateNum[t] = n * n;
        return;
    }
    int cnt = 0;
    bool isPos;
    int same = isSame();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            isPos = true;
            int c = j;
            for(int k = 0; k < sz - 1; k++) {
                if(c == n) { 
                    isPos = false;
                    break;
                }
                if(map[i][c] + structure[k] != map[i][c + 1] + structure[k + 1]) {
                    isPos = false;
                    break;
                }
                c++;
            }
            if(isPos) {
                cnt++;
            }
            c = i;
            isPos = true;
            for(int k = 0; k < sz - 1; k++) { //k 세로 확인!!
                if(c == n) {
                    isPos = false;
                    break;
                }
                if(map[c][j] + structure[k] != map[c + 1][j] + structure[k + 1]) {
                    isPos = false;
                    break;
                }
                c++;
            }
            if(isPos) {
                cnt++;
            }
            if(!same) {
                c = j;
                isPos = true;
                for(int k = sz - 1; k > 0; k--) { //k 가로 뒤집어 확인!!
                    if(c == n) {
                        isPos = false;
                        break;
                    }
                    if(map[i][c] + structure[k] != map[i][c + 1] + structure[k - 1]) {
                        isPos = false;
                        break;
                    }
                    c++;
                }
                if(isPos) {
                    cnt++;
                }
                c = i;
                isPos = true;
                for(int k = sz - 1; k > 0; k--) { //k 세로 뒤집어 확인!!
                    if(c == n) {
                        isPos = false;
                        break;
                    }
                    if(map[c][j] + structure[k] != map[c + 1][j] + structure[k - 1]) {
                        isPos = false;
                        break;
                    }
                    c++;
                }
                if(isPos) {
                    cnt++;
                }
            }
        }
    }

    candidateNum[t] = cnt;
}

int numberOfCandidate(int M, int mStructure[5])
{
    int t = 0;
    for(int i = 0; i < M; i++) {
        t = t * 10 + mStructure[i];
    }
	return candidateNum[t];
}


void copyMap() {
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= n + 1; j++) {
            temp[i][j] = map[i][j];
        }
    }
}

int calcArea(int seaLevel) {
    queue<pair<int, int> > q;
    int x, y, nx, ny, seaCnt = 1;

    q.push(make_pair(0, 0)); //외곽 테두리 물부터 퍼짐
    temp[0][0] = -1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int d = 0; d < 4; d++) {
            nx = x + dx[d];
            ny = y + dy[d];
            if(nx < 0 || nx >= n + 2 || ny < 0 || ny >= n + 2)
                continue;
            if(temp[nx][ny] == -1)
                continue;
            if(temp[nx][ny] >= seaLevel) //해수면 높이보다 같거나 높으면 안퍼짐
                continue;
            
            q.push(make_pair(nx, ny));
            temp[nx][ny] = -1;
            ++seaCnt;
        }
    }

    return ((n + 2)*(n + 2)) - seaCnt;
}


int maxArea(int M, int mStructure[5], int mSeaLevel)
{
    int maxAreaCnt = -1;
    int cnt = 0;
    bool isPos;
    sz = M;

    //구조물 mStructure를 설치할 방법이 없는 경우에는, -1을 반환한다.
    if(numberOfCandidate(M, mStructure) == 0) {
        return -1;
    }
    
    int same = true;
    for(int i = 0; i < sz; i++) {
        if(mStructure[i] != mStructure[sz - 1 - i]) {
            same = false;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            isPos = true;
            int c = j; 
            for(int k = 0; k < sz - 1; k++) {
                if(c == n) {
                    isPos = false;
                    break;
                }
                if(map[i][c] + mStructure[k] != map[i][c + 1] + mStructure[k + 1]) {
                    isPos = false;
                    break;
                }
                c++;
            }
            if(isPos) {
                copyMap();
                for(int s = 0; s < sz; s++) {
                    temp[i][j + s] += mStructure[s];
                }
                maxAreaCnt = max(maxAreaCnt, calcArea(mSeaLevel));
            }
            c = i;
            isPos = true;
            for(int k = 0; k < sz - 1; k++) { //k 세로 확인!!
                if(c == n) {
                    isPos = false;
                    break;
                }
                if(map[c][j] + mStructure[k] != map[c + 1][j] + mStructure[k + 1]) {
                    isPos = false;
                    break;
                }
                c++;
            }
            if(isPos) {
                copyMap();
                for(int s = 0; s < sz; s++) {
                    temp[i + s][j] += mStructure[s];
                }
                maxAreaCnt = max(maxAreaCnt, calcArea(mSeaLevel));
            }
            if(!same) {
                c = j;
                isPos = true;
                for(int k = sz - 1; k > 0; k--) { //k 가로 뒤집어 확인!!
                    if(c == n) {
                        isPos = false;
                        break;
                    }
                    if(map[i][c] + mStructure[k] != map[i][c + 1] + mStructure[k - 1]) {
                        isPos = false;
                        break;
                    }
                    c++;
                }
                if(isPos) {
                    copyMap();
                    for(int s = 0; s < sz; s++) {
                        temp[i][j + s] += mStructure[sz - 1 - s];
                    }
                    maxAreaCnt = max(maxAreaCnt, calcArea(mSeaLevel));
                }
                c = i;
                isPos = true;
                for(int k = sz - 1; k > 0; k--) { //k 세로 뒤집어 확인!!
                    if(c == n) {
                        isPos = false;
                        break;
                    }
                    if(map[c][j] + mStructure[k] != map[c + 1][j] + mStructure[k - 1]) {
                        isPos = false;
                        break;
                    }
                    c++;
                }
                if(isPos) {
                    copyMap();
                    for(int s = 0; s < sz; s++) {
                        temp[i + s][j] += mStructure[sz - 1 - s];
                    }
                    maxAreaCnt = max(maxAreaCnt, calcArea(mSeaLevel));
                }
            }
        }
    }
	return maxAreaCnt;
}
