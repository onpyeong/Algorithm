#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//S, T
vector<pair<int, int>> v;
//끝나는 시간이 가장 빠른 강의 순 
priority_queue<int, vector<int>, greater<int>> class_pq;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    
    class_pq.push(v[0].second);
    for(int i = 1; i < v.size(); i++) {
        int end_time = class_pq.top();
        if(end_time <= v[i].first) {
            class_pq.pop();
            class_pq.push(v[i].second);
        }else{
            class_pq.push(v[i].second);
        }
    }
    
    cout << class_pq.size();

    return 0;
}
