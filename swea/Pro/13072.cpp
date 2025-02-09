#define MAX 100005
#include <iostream>

using namespace std;

int version[MAX]; //병사 현재 버전 -> -1이면 삭제
int team[MAX]; //병사의 팀 번호
int soldier_cnt; //정적 idx
struct Soldier{
    int id;
    int v;
    Soldier* nxt;
    Soldier() {};
}soldierPool[500055]; //정적 할당 -> 최대 고용 병사 수보다 커야 함

struct Team{ //팀마다 점수별 링크드 리스트 포인터
    Soldier* head[6]; 
    Soldier* tail[6];
}soldiers[6];

Soldier* newSoldier(int mID) { //버전 업하고 반환
    Soldier* s = &soldierPool[soldier_cnt++];
    s->id = mID;
    s->v = ++version[mID];
    s->nxt = nullptr;
    return s;
}

void init() //테스트 케이스 초기화
{
    for(int i = 0; i < soldier_cnt + 5; i++) {
        version[i] = 0;
        team[i] = 0;
    }
    soldier_cnt = 0;
    for(int i = 1; i < 6; i++) {
        for(int j = 1; j < 6; j++) {
            //빈 노드로 초기화
            soldiers[i].tail[j]= soldiers[i].head[j] = newSoldier(0);
        }
    }
}

void hire(int mID, int mTeam, int mScore)
{
    Soldier* s = newSoldier(mID);
    team[mID] = mTeam;
    soldiers[mTeam].tail[mScore] -> nxt = s;
    soldiers[mTeam].tail[mScore] = s;
}

void fire(int mID)
{
    version[mID] = -1; //lazy
}

void updateSoldier(int mID, int mScore)
{
    hire(mID, team[mID], mScore);
}

void updateTeam(int mTeam, int mChangeScore)
{
    if(mChangeScore > 0) {
        for(int sc = 5; sc >= 1; sc--) {
            int newScore = sc + mChangeScore;
            if(newScore > 5)
                newScore = 5;
            if(newScore == sc)
                continue;
            if(soldiers[mTeam].head[sc] -> nxt == nullptr) //비었으면
                continue;
            //연결하기 sc를 newScore 뒤로
            soldiers[mTeam].tail[newScore] -> nxt = soldiers[mTeam].head[sc] -> nxt;
            soldiers[mTeam].tail[newScore] = soldiers[mTeam].tail[sc];
            soldiers[mTeam].head[sc] -> nxt = nullptr;
            soldiers[mTeam].tail[sc] = soldiers[mTeam].head[sc];
        }
    }else if(mChangeScore < 0){
        for(int sc = 1; sc <= 5; sc++) {
            int newScore = sc + mChangeScore;
            if(newScore < 1)
                newScore = 1;
            if(newScore == sc)
                continue;
            if(soldiers[mTeam].head[sc] -> nxt == nullptr)
                continue;
            //연결하기 sc를 newScore 뒤로
            soldiers[mTeam].tail[newScore] -> nxt = soldiers[mTeam].head[sc] -> nxt; //유효노드로 연결
            soldiers[mTeam].tail[newScore] = soldiers[mTeam].tail[sc];
            soldiers[mTeam].head[sc] -> nxt = nullptr;
            soldiers[mTeam].tail[sc] = soldiers[mTeam].head[sc];
        }

    }
}

int bestSoldier(int mTeam)
{
    int maxScoreMID = 0;
    for(int sc = 5; sc >= 1; sc--) {
        maxScoreMID = 0;
        if(soldiers[mTeam].head[sc] -> nxt == nullptr) { //비었으면
            continue;
        }
        Soldier * s = soldiers[mTeam].head[sc] -> nxt;
        while(s != nullptr) { //같은 점수 돌면서 있으면 id 갱신
            if(s -> v == version[s -> id]) {
                maxScoreMID = max(maxScoreMID, s-> id);
            }
            s = s -> nxt;
        }
        if(maxScoreMID != 0)
            break;
    }
    return maxScoreMID;
}
