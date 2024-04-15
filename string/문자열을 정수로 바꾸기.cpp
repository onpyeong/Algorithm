#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isMinus = false;
    int i = 0;
    if(s[i] == '-') {
        isMinus = true;
        i++;
    }else if(s[i] == '+') {
        i++;
    }
    while(i < s.size()) {
        answer = answer * 10 + (s[i++] - '0');
    }
    if(isMinus) answer = -answer;
    return answer;
}
