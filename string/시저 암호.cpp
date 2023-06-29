#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            answer += " ";
            continue;
        }
        
        int sum = s[i] + n;
        if('a' <= s[i] && s[i] <= 'z')  {
            if(sum > 'z'){
                sum -= 26;
            }
        }
        if('A' <= s[i] && s[i] <= 'Z')  {
            if(sum > 'Z'){
                sum -= 26;
            }
        } 
        answer += sum;
    }
    return answer;
}
