#include <iostream>
using namespace std;

struct Node {
  char c;
  Node* nxt;
  Node* prev;
};
Node* cursor;
Node* first;

void insertNodeToRight(char x) {
  Node* newNode = new Node{x, NULL, NULL}; //new Heap에 생성해야 살아있음
  cursor->nxt = newNode;
  newNode->prev = cursor;
  cursor = newNode;
}

void moveCursorLeft() {
  if(cursor != first)
    cursor = cursor->prev;
}

void moveCursorRight() {
  if(cursor->nxt != NULL)
    cursor = cursor->nxt;
}

void deleteLeft() {
  if(cursor == first)
    return;
  Node * tmp = cursor;
  cursor->prev->nxt = cursor->nxt;
  if(cursor->nxt != NULL)
    cursor->nxt->prev = cursor->prev;
  cursor = cursor->prev;
  delete tmp;
}

void insertNodeToLeft(char x) {
  Node* newNode = new Node{x, NULL, cursor};
  newNode->nxt = cursor->nxt;
  if(cursor->nxt != NULL)
    cursor->nxt->prev = newNode;
  cursor->nxt = newNode;
  cursor = newNode;
}

int main() 
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  string input;
  char inst, x;
  int M;
  
  Node start = {'S', NULL, NULL};
  cursor = first = &start;
  
  cin >> input;
  for(char c: input) {
    insertNodeToRight(c);
  }
  
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> inst;
    if(inst == 'L') { //커서를 왼쪽으로 한 칸 옮김
      moveCursorLeft();
    }else if(inst == 'D') { //커서를 오른쪽으로 한 칸 옮김
      moveCursorRight();
    }else if(inst == 'B') { //커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
      deleteLeft();
    }else { //x라는 문자를 커서 왼쪽에 추가함
      cin >> x;
      insertNodeToLeft(x);
    }
  }

  first = first -> nxt;
  while(true) {
    cout << first->c;
    if(first->nxt == NULL)
      break;
    first = first->nxt;
  }
  cout << "\n";
  return 0;
}
