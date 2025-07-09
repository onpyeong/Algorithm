#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
string s;
vector<string> v;
map<string, int> sum;

bool compare(const string &s1, const string &s2) {
  if(s1.size() == s2.size()) {
    if(sum[s1] == sum[s2]) {
      return s1 < s2;
    }
    return sum[s1] < sum[s2];
  }
  
  return s1.size() < s2.size();
}

int main() {
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> s;
      v.push_back(s);
      int digit_sum = 0;
      for(int j = 0; j < s.size(); j++) {
        if(isdigit(s[j])) {
          digit_sum += (s[j] - '0');
        }
      }
      sum[s] = digit_sum;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
      cout << v[i] << "\n";
    }
    
    return 0;
}
