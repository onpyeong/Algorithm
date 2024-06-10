#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<pair<int, int> > q;
    q.push({0, -1});
    while(!q.empty()) {
        int value = q.front().first;
        int idx = q.front().second + 1;
        q.pop();
        if(idx == numbers.size()) {
            if(value == target)
                answer++;
            continue;
        }
        q.push({value + numbers[idx], idx});
        q.push({value - numbers[idx], idx});
    }
    
    return answer;
}
