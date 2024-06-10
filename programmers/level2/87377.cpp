//프로그래머스 - 교점에 별 만들기
#include <string>
#include <vector>
#define INF 20000000001

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector <pair<long long, long long>> dots;

    long long min_x = INF, max_x = -INF;
    long long min_y = INF, max_y = -INF;
    
    for(int i = 0; i < line.size(); i++) {
        for(int j = i + 1; j < line.size(); j++) {
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            
            long long AD_BC = A*D - B*C;
            if(AD_BC != 0) {
                long long BF_ED = B*F - E*D;
                long long EC_AF = E*C - A*F;
                //정수인지 판단해서 교점 리스트에 담기
                if(BF_ED % AD_BC == 0 && EC_AF % AD_BC == 0){
                    long long x = BF_ED / AD_BC;
                    long long y = EC_AF / AD_BC;
                    dots.push_back(make_pair(x, y));
                    //* 교점 리스트 dots 최대 최소값 구하기
                    min_x = min(x, min_x);
                    max_x = max(x, max_x);
                    min_y = min(y, min_y);
                    max_y = max(y, max_y);
                }
            }
        }
    }
    
    for(int i = 0; i < max_y - min_y + 1; i++) {
        string s = "";
        for(int j = 0; j < max_x - min_x + 1; j++){
            s += ".";
        }
        answer.push_back(s);    
    }
    
    for(auto dot: dots) {
        answer[max_y - dot.second][dot.first - min_x] = '*';
    }
    
    return answer;
}
