#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
pair<int, int> m, e;
bool map[51][51];
int bestPath[51][51]; //집부터 메두사까지의 최단 경로
int personPath[51][51]; //메두사부터 모든 전사까지의 최단 경로
bool visible[51][51]; //메두사가 볼 수 있는 범위
int checkPerson[51][51]; //전사가 있는지 여부
bool isDie[301];
bool isRock[301];
vector<pair<int, int>> people;
int d[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; //상하좌우 우상, 우하, 좌하, 좌상
int moveCnt, rockCnt, attackCnt, dieCnt;

bool isOut(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N; 
}

void find_best_path(int sx, int sy, bool isMoveMedusa) {
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int nx, ny;

    q.push({sx, sy});
    if(isMoveMedusa)
        bestPath[sx][sy] = 1;
    else
        personPath[sx][sy] = 1;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(isMoveMedusa && cur.first == m.first && cur.second == m.second)
            break;
        for(int i = 0; i < 4; i++) {
            nx = cur.first + d[i][0];
            ny = cur.second + d[i][1];
            if(isOut(nx, ny))
                continue;
            if(isMoveMedusa) {
                if(map[nx][ny] || bestPath[nx][ny] != 0)
                    continue;
                q.push({nx, ny});
                bestPath[nx][ny] = bestPath[cur.first][cur.second] + 1;
            }else {
                if(personPath[nx][ny] != 0)
                    continue;
                q.push({nx, ny});
                personPath[nx][ny] = personPath[cur.first][cur.second] + 1;
            }
        }
    }
}

int move_medusa() {
    int nx, ny;
    int tx = m.first, ty = m.second;
    for(int i = 0; i < 4; i++) {
        nx = m.first + d[i][0];
        ny = m.second + d[i][1];
        if(isOut(nx, ny))
            continue;
        if(bestPath[nx][ny] == 0 || bestPath[nx][ny] >= bestPath[tx][ty])
            continue;
        tx = nx;
        ty = ny;
        break;
    }
    if(tx == m.first && ty == m.second) {
        return -1;
    }
    m.first = tx;
    m.second = ty;
    if(checkPerson[tx][ty] != 0) {
        for(int i = 0; i < M; i++) {
            if(!isDie[i] && people[i].first == tx && people[i].second == ty) {
                isDie[i] = true;
                dieCnt++;
            }
        }
    }
    if(tx == e.first && ty == e.second) {
        return 0;
    }
    return 1;
}

//상하좌우에 따른 시야각 방향
//상 0 하 1 좌 2 우 3
int vDir[4][3] = {
    {0, 4, 7},
    {1, 5, 6},
    {2, 6, 7},
    {3, 4, 5}
};

int calc_person_dir(int x, int y) {
    if(x < m.first) { //위
        if(y < m.second) {
            return 7;
        }else if(y == m.second) {
            return 0;
        }else {
            return 4;
        }
    }else if(x > m.first) { //아래
        if(y < m.second) {
            return 6;
        }else if(y == m.second) {
            return 1;
        }else {
            return 5;
        }
    }else {
        if(y < m.second) {
            return 2;
        }else if(y > m.second) {
            return 3;
        }
    }
}

struct DirPerson{
    int x;
    int y;
    int dir;
};

queue<DirPerson> pq;

void see_medusa(int i) {
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int nx, ny;

    q.push({m.first, m.second});
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for(int j = 0; j < 3; j++) {
            nx = cur.first + d[vDir[i][j]][0];
            ny = cur.second + d[vDir[i][j]][1];
            if(isOut(nx, ny))
                continue;
            if(visible[nx][ny])
                continue;
            q.push({nx, ny});
            visible[nx][ny] = true;
            if(checkPerson[nx][ny]) { //사람 있으면 pq에 넣기
                for(int k = 0; k < M; k++) {
                    if(!isDie[k] && people[k].first == nx && people[k].second == ny) {
                        pq.push({nx, ny, calc_person_dir(nx, ny)});
                    }
                }
            }
        }
    }
}

void cover_person(int mDir) {
    int pDir, dirSize;
    DirPerson pCur;
    int nx, ny;

    while(!pq.empty()) {
        pCur = pq.front();
        pDir = pCur.dir;
        pq.pop();
        dirSize = (pDir < 4)? 1 : 2;
        for(int j = 0; j < dirSize; j++) {
            if(j == 0) {
                nx = pCur.x + d[pDir][0];
                ny = pCur.y + d[pDir][1];
            }else{
                nx = pCur.x + d[mDir][0];
                ny = pCur.y + d[mDir][1];
            }
            if(isOut(nx, ny))
                continue;
            if(!visible[nx][ny])
                continue;
            pq.push({nx, ny, pDir});
            visible[nx][ny] = false;
        }
    }
}

void make_rock() {
    //메두사 시야 방향 찾기
    int maxPCnt = -1, pCnt;
    int selectDir = 0;

    for(int i = 0; i < 4; i++) { //모든 방향 검사
        pCnt = 0;
        memset(visible, 0, sizeof(visible));

        //메두사 방향으로 전부 visbile true
        see_medusa(i);
        
        //기사 배열돌면서 범위 visible = false;
        cover_person(i);

        for(int k = 0; k < M; k++) {
            if(!isDie[k] && visible[people[k].first][people[k].second]) {
                pCnt++;
            }
        }
        if(maxPCnt < pCnt) {
            maxPCnt = pCnt;
            selectDir = i;
        }
    }
    
    memset(visible, 0, sizeof(visible));
    for(int i = 0; i < M; i++)
        isRock[i] = false;
    //실제로 돌로 만들기
    see_medusa(selectDir);
    cover_person(selectDir);
    for(int k = 0; k < M; k++) {
        if(!isDie[k] && visible[people[k].first][people[k].second]) {
            isRock[k] = true;
            rockCnt++;
        }
    }
}

bool visited[51][51];
int d2[4] = {2, 3, 0, 1}; //0123 상하좌우

void move_people() {
    memset(personPath, 0, sizeof(personPath));
    //메두사로부터 모든 병사까지의 거리
    find_best_path(m.first, m.second, false);

    for(int k = 0; k < M; k++) {
        int nx, ny;
        for(int t = 0; t < 2; t++) {
            if(isDie[k] || isRock[k])
                continue;
            int tx = people[k].first, ty = people[k].second;
            for(int i = 0; i < 4; i++) { //상하좌우 순으로 보면서
                if(t == 0) {
                    nx = people[k].first + d[i][0];
                    ny = people[k].second + d[i][1];
                }else {
                    nx = people[k].first + d[d2[i]][0];
                    ny = people[k].second + d[d2[i]][1];
                }
                if(isOut(nx, ny))
                    continue;
                if(visible[nx][ny] || personPath[nx][ny] >= personPath[tx][ty])
                        continue;
                tx = nx;
                ty = ny;
                break;
            }
            if(tx == people[k].first && ty == people[k].second) {
                break;
            }
            if(tx == m.first && ty == m.second) {
                attackCnt++;
                moveCnt++;
                checkPerson[people[k].first][people[k].second]--;
                isDie[k] = true;
                dieCnt++;
                continue;
            }
            people[k].first = tx;
            people[k].second = ty;
            checkPerson[tx][ty]++;
            moveCnt++;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;

    cin >> N >> M;
    cin >> x >> y;
    m = {x, y};
    cin >> x >> y;
    e = {x, y};
    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        people.push_back({x, y});
        checkPerson[x][y]++;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    find_best_path(e.first, e.second, true); 
    while(true) {
        moveCnt = 0;
        rockCnt = 0;
        attackCnt = 0;
        int r = move_medusa();
        if(r == 0 || r == -1) {
            cout << r << "\n";
            break;
        }
        if(dieCnt < M) {
            make_rock();
            move_people();
        }
        cout << moveCnt << " " << rockCnt << " " << attackCnt << "\n";
    }
    return 0;
}
