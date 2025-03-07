#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, K;

struct Trie{
  map<string, Trie*> next;
  
  Trie(): next() {}
  
  void insert(vector<string> &foods, int sz) { //단어들을 트라이 구조로 담는다!
    Trie* now = this;
    for(int i = 0; i < sz; i++) {
      if(now->next.find(foods[i]) == now->next.end()) {
        now->next[foods[i]] = new Trie();
      }
      now = now->next[foods[i]];
    }
  }
  
  void printTrie(int depth) { //dfs로 방문한다.
    for(auto& nxt : next) {
      for(int i = 0; i < depth; i++) {
        cout << "--";
      }
      cout << nxt.first << "\n";
      nxt.second->printTrie(depth + 1);
    }
  }
  
};

Trie* root;
vector<string> foods(16);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    root = new Trie();
    for(int i = 0; i < N; i++) {
      cin >> K;
      for(int j = 0; j < K; j++) {
        cin >> foods[j];
      }
      root->insert(foods, K); //단어들이 하나의 문자열이라고 생각하면 됨!
    }
    root->printTrie(0);
    return 0;
}
