#include <iostream>

using namespace std;

int main() 
{
    int answer = 0; 
    string s;
    cin >> s;
    int s_size = s.size();
    
    for(int i = 0; i < s_size; i++) {
      if(s[i] == 'c') {
        if(i + 1 < s_size && (s[i + 1] == '=' || s[i + 1] == '-')) {
          i++;
        }
        answer++;
      }else if(s[i] == 'd') {
        if(i + 2 < s_size && s[i + 1] == 'z' && s[i + 2] == '=') {
          i += 2;
        }else if(i + 1 < s_size && s[i + 1] == '-') {
          i++;
        }
        answer++;
      }else if(i + 1 < s_size && ((s[i] == 'l' && s[i + 1] == 'j') || 
      (s[i] == 'n' && s[i + 1] == 'j') || (s[i] == 's' && s[i + 1] == '=')
      || (s[i] == 'z' && s[i + 1] == '='))) {
        answer++;
          i++;
      }else {
        answer++;
      }
    }
    
    cout << answer;
    return 0;
}
