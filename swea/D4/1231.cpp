#include <iostream>

using namespace std;

int T = 10, N, idx, k;
string input;
char alpha[105];
int lc[105];
int rc[105];
string word;

void init() {
  word = "";
}

void inOrder(int n) {
  if(lc[n] != 0) inOrder(lc[n]);
  word += alpha[n];
  if(rc[n] != 0) inOrder(rc[n]);
}

int makeNum(int sz) {
  int num = 0;
  while(k < sz && input[k] != ' ') {
    num += num * 10 + (input[k++] - '0');
  }
  return num;
}

int main() 
{
    for(int t = 1; t <= T; t++) {
      init();
      cin >> N;
      cin.ignore(); //버퍼 비우기 \n 버림
      for(int i = 0; i < N; i++) {
        getline(cin, input); //공백 포함해서 한 줄 입력
        k = 0;
        idx = makeNum(input.size());
        alpha[idx] = input[++k];
        k += 2;
        lc[idx] = makeNum(input.size());
        k++;
        rc[idx] = makeNum(input.size());
      }
      
      inOrder(1);
      
      cout << "#" << t << " " << word << "\n";
    }
    return 0;
}
