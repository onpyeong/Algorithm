#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
   
    for(int i = 1; i <= s.size() / 2; i++) {
        string t = "";
        for(int j = 0; j < s.size();) {
            int cnt = 0;
            string part = s.substr(j, i);
            while(j < s.size() && part == s.substr(j, i)) {
                cnt++;
                j += i;
            }
            if(cnt > 1)
                t += to_string(cnt);
            t += part;
        }
        answer = min(answer, (int)t.size());
    }
    return answer;
}
