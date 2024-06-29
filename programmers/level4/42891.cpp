#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int solution(vector<int> food_times, long long k) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < food_times.size(); i++)
        pq.push({food_times[i], i + 1});
    
    long long t, round = 0, max_round = 0;
    while (!pq.empty()) {
        t = pq.top().first - max_round; //남은 음식으로 돌 수 있는 최대 바퀴 수
        round = k / pq.size(); //시간 기준 돌 수 있는 최대 바퀴 수
        if (round == 0) break;
        if (round >= t)
            round = t;
        k -= pq.size() * round;
        max_round += round;
        while (!pq.empty() && pq.top().first <= max_round){
            pq.pop();
        }
    }
    
    if(pq.empty()) {
        answer = -1;
    }else { //남아 있는 k 시간만큼 먹기
        int i;
        for(i = 0; i < food_times.size(); i++) {
            if(k < 0)
                break;
            if(food_times[i] > max_round) {
                k--;
            }
        }
        answer = i;
    }
    
    return answer;
}
