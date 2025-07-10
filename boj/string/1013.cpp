/*
// c++ regex 사용하기
#include <iostream>
#include <regex>

using namespace std;

int T;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    regex pattern("(100+1+|01)+"); // 정규표현식
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      cin >> s;
      if(regex_match(s, pattern)) { // 문자열 s가 pattern과 일치하는지
        cout << "YES\n";
      }else {
        cout << "NO\n";
      }
    }
    
    return 0;
}
*/


#include <iostream>

using namespace std;

int T;
string s;

//(100+1+ | 01)+
bool filter() {
  int len = s.size();
  int i = 0;
  while(i < len) {
    if(s[i] == '1') {
      if(i + 3 < len && s[i + 1] == '0' && s[i + 2] == '0') { //100
        i += 3;
        while(i < len && s[i] == '0') //1이 나올 때까지 pass
          i++;
        if(i == len)
          return false;
        while(i < len && s[i] == '1') //1+ 체크
          i++;
        if(len == i)
          return true;
        if(i + 1 < len && s[i + 1] == '1') { //다시 01
          i += 2;
          continue;
        }
        if(i + 1 == len) { //0으로 끝난 경우
          return false;
        }
        if(s[i - 2] != '1') { //1001001 인 경우!
          return false;
        }
        i--; //1001100~
        continue;
      }else { 
        return false;
      }
    }else if(i + 1 < len && s[i + 1] == '1') { //01
      i += 2;
    }else {
      return false;
    }
  }
  return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int i = 0; i < T; i++) {
      cin >> s;
      if(filter()) {
        cout << "YES\n";
      }else {
        cout << "NO\n";
      }
    }
    
    return 0;
}
