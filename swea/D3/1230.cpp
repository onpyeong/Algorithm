#include <iostream>

using namespace std;

int T, N, code, inst_cnt;
char inst;
int x, y;

struct Node{
  int code;
  Node* nxt;
};

int node_cnt;
Node node_list[1000000];
Node* head;
Node* tail;

Node* newNode(int c) {
  node_list[node_cnt].code = c;
  node_list[node_cnt].nxt = nullptr;
  return &node_list[node_cnt++];
}

void init() {
  node_cnt = 0;
  head = newNode(0);
  tail = head;
}

void add(int c) {
  Node* node = newNode(c);
  tail -> nxt = node;
  tail = node;
  if(head -> nxt == nullptr) {
    head -> nxt = node;
  }
}

Node* findKNode(int k) {
  Node* n = head;
  for(int i = 0; i < k; i++) {
    if(n -> nxt != nullptr)
      n = n -> nxt;
    else
      return n;
  }
  return n;
}

void insert(int k, int c) {
  Node* n = findKNode(k);
  Node* iNode = newNode(c);
  iNode -> nxt = n -> nxt;
  n -> nxt = iNode;
}

void removeNode(int k, int y) {
  Node* n = findKNode(k);
  if(n != head) {
    for(int i = 0; i < y; i++) {
      if(n -> nxt != nullptr) {
        n -> nxt = n -> nxt -> nxt;
      } else{
        tail = n;
        return;
      }
    }
  }
}

void print() {
  Node* n = head -> nxt;
  for(int i = 0; i < 10; i++) {
    if(n == nullptr)
      break;
    cout << n -> code << " ";
    n = n -> nxt;
  }
  cout << "\n";
}


int main() 
{
  T = 10;
  for(int t = 1; t <= T; t++) {
    cin >> N;
    init();
    for(int i = 0; i < N; i++) {
      cin >> code;
      add(code);
    }
    
    cin >> inst_cnt;
    for(int i = 0; i < inst_cnt; i++) {
      cin >> inst;
      if(inst == 'I') {
        cin >> x >> y;
        for(int j = 0; j < y; j++) {
          cin >> code;
          insert(x + j, code);
        }
       
      }else if(inst == 'D') {
        cin >> x >> y;
        removeNode(x, y);
      }else {
        cin >> y;
        for(int j = 0; j < y; j++) {
          cin >> code;
          add(code);
        }
      }
    }
    
    cout << "#" << t << " ";
    
    print();
    
  }
  return 0;
}
