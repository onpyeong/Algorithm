#include <iostream>
#include <deque>

using namespace std;

int N, M;
int pick[51];
deque<int> dq;
int dq_size;
int answer;

int main() {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
      dq.push_back(i);
    }
    
    for(int i = 0; i < M; i++) {
      cin >> pick[i];      
    }  

    dq_size = dq.size();
    for(int i = 0; i < M; i++) {
      while(dq[0] != pick[i]) {
        int j = 0;
        for(; j < dq_size; j++) {
          if(pick[i] == dq[j]) {
            break;
          }
        }
        if(j <= dq_size / 2) {
          for(int k = 0; k < j; k++) {
            dq.push_back(dq[0]);
            dq.pop_front();
            answer++;
          }
        }else {
          for(int k = dq_size - 1; k >= j; k--) {
            dq.push_front(dq[dq_size - 1]);
            dq.pop_back();
            answer++;
          }
        }
      }
      dq.pop_front();
      dq_size--;
    }
    
    cout << answer;
    
    return 0;
}
