#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = 0, e = (long long)n * (*max_element(times.begin(), times.end())), mid;
    while(s + 1 < e) {
        mid = (s + e) / 2;
        long long cnt = 0;
        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        if(cnt < n) {
            s = mid;
        }else {
            e = mid;
        }
    }
    
    answer = e;
    
    return answer;
}
