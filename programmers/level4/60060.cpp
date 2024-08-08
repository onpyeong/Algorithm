#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int words_size;
map<int, vector<string>> w, b; //길이별 단어

int w_lower_bound(string q, int q_size) {
    int s = -1, e = w[q_size].size();
    while(s + 1 < e) {
        int m = (s + e) / 2;
        if(w[q_size][m] < q) {
            s = m; 
        }else {
            e = m;
        }
    }
    return e;
    
}

int b_lower_bound(string q, int q_size) {
    int s = -1, e = b[q_size].size();
    while(s + 1 < e) {
        int m = (s + e) / 2;
        if(b[q_size][m] < q) {
            s = m; 
        }else {
            e = m;
        }
    }
    return e;
}



int w_upper_bound(string q, int q_size) {
    int s = -1, e = w[q_size].size();
    while(s + 1 < e) {
        int m = (s + e) / 2;
        if(w[q_size][m] <= q) {
            s = m; 
        }else {
            e = m;
        }
    }
    return s;
}

int b_upper_bound(string q, int q_size) {
    int s = -1, e = b[q_size].size();
    while(s + 1 < e) {
        int m = (s + e) / 2;
        if(b[q_size][m] <= q) {
            s = m; 
        }else {
            e = m;
        }
    }
    return s;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    words_size = words.size();
    for(int i = 0; i < words_size; i++) {
        w[words[i].size()].push_back(words[i]);
        reverse(words[i].begin(), words[i].end());
        b[words[i].size()].push_back(words[i]);
    }
    
    for(int i = 0; i < w.size(); i++) {
        sort(w[i].begin(), w[i].end());
    }
    for(int i = 0; i < b.size(); i++) {
        sort(b[i].begin(), b[i].end());
    }
    
    for(string q : queries) {
        bool is_reverse = false;
        if(q[0] == '?') {
            is_reverse = true;
            reverse(q.begin(), q.end());
        }
        
        int q_size = q.size();
        int i;
        for(i = 0; i < q_size; i++)
            if(q[i] == '?')
                break;
        string u_str = q.substr(0, i);
        for(int k = i; k < q_size; k++) {
            u_str += 'z';
        }
        
        if(is_reverse) {
            answer.push_back(b_upper_bound(u_str, q_size) - b_lower_bound(q, q_size) + 1);
        }else {
            answer.push_back(w_upper_bound(u_str, q_size) - w_lower_bound(q, q_size) + 1);
        }
    }
    return answer;
}
