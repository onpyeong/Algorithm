#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int pick_score[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};

struct Score{
    int d = 0;
    int i = 0;
    int s = 0;
};

vector<Score> v;

bool compare(const Score &a, const Score &b) {
    if(a.s == b.s){
        if(a.i == b.i)
            return a.d > b.d;
        return a.i > b.i;
    }
    return a.s > b.s;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int m_size = minerals.size();
    int pick_total = 0;
    for(int i = 0; i < 3; i++) {
        pick_total += picks[i];
    }
    pick_total *= 5;

    for(int i = 0; i < m_size; i += 5) {
        Score s;
        if(i >= pick_total) //곡괭이 개수를 넘어가는 광물은 포함 안함
            break;
        for(int j = i; j < i + 5; j++) { //5개씩 구간 나누기
            if(j == m_size) {
                break;
            }
            int m;
            if(minerals[j] == "diamond") {
                m = 0;
            }else if(minerals[j] == "iron") {
                m = 1;
            }else {
                m = 2;
            }
            s.d += pick_score[0][m]; 
            s.i += pick_score[1][m];
            s.s += pick_score[2][m];
        }
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare); //돌 곡괭이 피로도가 높은 순
    
    int v_size = v.size();
    int idx = 0;
    for(int i = 0; i < 3; i++) { //다이아 곡괭이부터 소진
        int p = picks[i];
        while(p--) {
            if(i == 0) {
                answer += v[idx].d;
            }else if(i == 1) {
                answer += v[idx].i;
            }else {
                answer += v[idx].s;
            }
            idx++;
            if(idx == v_size)
                break;
        }
        if(idx == v_size)
            break;
    }
    
    return answer;
}
