#include <iostream>
using namespace std;

int T, N, M, L;
char inst;
int idx, x;

struct Node{
  int v;
  Node* nxt;
} nodes[100005];

Node* head;
Node* tail;
int node_cnt;

Node* newNode(int v) {
  Node* n = &nodes[node_cnt++];
  n -> v = v;
  n -> nxt = nullptr;
  return n;
}

void init() {
  node_cnt = 0;
  head = tail = newNode(0);
}

Node* findNode(int idx) {
  Node* n = head;
  for(int i = -1; i < idx; i++) {
    n = n -> nxt;
    if(n == nullptr) {
      break;
    }
  }
  return n;
}

void add(int v) {
  Node* n = newNode(v);
  tail -> nxt = n;
  tail = n;
}


void insert(int idx, int v) { //idx 앞에 추가
  Node* prev = findNode(idx - 1);
  Node* n = newNode(v); 
  n -> nxt = prev -> nxt;
  prev -> nxt = n;
}

void removeNode(int idx) { //idx 삭제
  Node* prev = findNode(idx - 1);
  prev -> nxt = prev -> nxt -> nxt;
  if(prev -> nxt == nullptr)
    tail = prev -> nxt;
}

void update(int idx, int v) {
  Node* n = findNode(idx);
  n -> v = v;
}

int main() 
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> T;
  for(int t = 1; t <= T; t++) {
    init( );
    cin >> N >> M >> L;
    for(int i = 0; i < N; i++) {
      cin >> x;
      add(x);
    }
    
    for(int i = 0; i < M; i++) {
      cin >> inst;
      if(inst == 'I') {
        cin >> idx >> x;
        insert(idx, x);
      }else if(inst == 'D') {
        cin >> idx;
        removeNode(idx);
      }else {
        cin >> idx >> x;
        update(idx, x);
      }
    }
    
    Node* n = findNode(L);
    cout << "#" << t << " " << ((n == nullptr) ? -1 : n -> v) << "\n";
  }
    return 0;
}
