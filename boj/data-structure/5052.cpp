#include <iostream>
#include <algorithm>

using namespace std;

int t, n;

struct Trie{
  Trie* nextNum[10];
  bool isEnd;
  
  Trie(): nextNum(), isEnd(0) {}
  
  void insert(string &str) {
    Trie* now = this;
    for(int i = 0; i < str.size(); i++) {
      int n = str[i] - '0';
      if(now->nextNum[n] == NULL) { //없으면 연결
        now->nextNum[n] = new Trie();
      }
      now = now->nextNum[n]; //다음 트라이로 이동
      if(i == str.size() - 1) { //마지막 글자이면
        now->isEnd = true; //끝 표시
      }
    }
  }
  
  bool find(string & str) {
    Trie* now = this;
    for(int i = 0; i < str.size(); i++) {
      int n = str[i] - '0';
      if(now->nextNum[n] == NULL) { //없으면 안겹침
        return false;
      }
      now = now->nextNum[n];
      if(now->isEnd && i != str.size() - 1) { //끝 글자인데, 나는 아직 끝나지 않았으면 -> 접두사
        return true;
      }
      
    }
    return false;
  }
  
};

Trie* root;
string words[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
      cin >> n;
      root = new Trie();
      for(int j = 0; j < n; j++) {
        cin >> words[j];
      }
      sort(words, words + n); //단어 길이 순으로 정렬
      
      bool isInvalid = false;
      for(int j = 0; j < n; j++) {
        if(root->find(words[j])) { //단어의 일부에 접두사가 이미 있으면 바로 pass
          isInvalid = true;
          break;
        }
        root->insert(words[j]); //안겹치면 insert
      }
      cout << ((isInvalid)? "NO\n" : "YES\n");
    }
    return 0;
}
