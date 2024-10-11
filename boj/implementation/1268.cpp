#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n;
int student[1001][5];
set<int> diffStudent[1001];
vector<pair<int, int>> captain;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> student[i][j];
        }
    }
    
    for(int i = 0; i < n - 1; i++) {
        for(int g = 0; g < 5; g++) {
            for(int j = i + 1; j < n; j++) {
                if(student[i][g] == student[j][g]) {
                    diffStudent[i].insert(j);
                    diffStudent[j].insert(i);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        captain.push_back({diffStudent[i].size(), i});
    }
    sort(captain.begin(), captain.end(), compare);
    
    cout << captain[0].second + 1;
    return 0;
}
