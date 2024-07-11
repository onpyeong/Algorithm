#include <string>
#include <vector>
#include <iostream>

using namespace std;

int len, dist_size, weak_size, answer = 9;
vector<int> d, space;
int choose_d[9];
bool is_used[9];

void choose_dist(int m) {
    if(m == dist_size) { //dist 순서 나열
        int idx;
        for(int s = 0; s < weak_size; s++) { //시작 weak
            int d_idx = 0, cnt = 0;
            idx = s;
            while(cnt < weak_size) {
                int sum = 0;
                idx = (idx + 1) % weak_size;
                cnt++;
                while(choose_d[d_idx] >= sum + space[idx]) {
                    cnt++;
                    sum += space[idx];
                    if(cnt == weak_size) {
                        break;
                    }
                    idx = (idx + 1) % weak_size;
                }
                d_idx++;
                if(d_idx == dist_size) {
                    break;
                }
            }
            if(cnt == weak_size) {
                answer = min(answer, d_idx);
            }
        }
        return;
    }
    for(int i = 0; i < dist_size; i++) {
        if(!is_used[i]) {
            is_used[i] = true;
            choose_d[m] = d[i];
            choose_dist(m + 1);
            is_used[i] = false;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    len = n;
    dist_size = dist.size();
    weak_size = weak.size();
    d = dist;
    
    space.push_back(weak[0] + n - weak[weak_size - 1]);
    for(int i = 1; i < weak_size; i++) {
        space.push_back(weak[i] - weak[i - 1]);
    }
    
    choose_dist(0);
    
    if(answer == 9)
        answer = -1;
    
    return answer;
}
