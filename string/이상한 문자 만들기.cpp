#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string word;
    
    int idx = 1;
    while(getline(ss, word, ' ')) {
        for(int i = 0; i < word.size(); i++) {
            if(i % 2 == 0) {
               answer += toupper(word[i]);
            }else {
                answer += tolower(word[i]);
            }
        }
        idx += word.size() - 1;
        while(s[idx++] == ' ')
            answer += " ";
    }
    return answer;
}
