#include <iostream>
#include <cmath>

using namespace std;

int N;

void print_cantor(string &s, int x, int s_idx) {
  if(x == 1)
    return;
  
  int t = x / 3;
  for(int i = s_idx + t; i < s_idx + t + t; i++) {
    s[i] = ' ';
  }
  print_cantor(s, t, s_idx);
  print_cantor(s, t, s_idx + t + t);
}

int main() {
    string t;
    while(getline(cin, t)) {
      N = stoi(t);
      string s(pow(3, N), '-');
      print_cantor(s, pow(3, N), 0);
      cout << s << "\n";  
    }
    return 0;
}
