#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 로봇의 현재 좌표
int x[105];
int y[105];
int robot_point[105]; 
bool robot_out[105];
unordered_map<int, int> next_points;

int point_to_num(int cx, int cy) { // 좌표 중복을 찾기 위한 해싱
    return cx * 100 + cy;
}

bool move_next_point(int robot, int dx, int dy) { // 최단거리 r 우선
    if(x[robot] < dx) {
        x[robot]++;
    }else if(x[robot] > dx) {
        x[robot]--;
    }else if(y[robot] < dy) {
        y[robot]++;
    }else if(y[robot] > dy) {
        y[robot]--;
    }
    if(x[robot] == dx && y[robot] == dy) {
        return false;
    }
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int routes_size = routes[0].size();
    int robots_size = routes.size();
    int out = 0;

    // 시작 좌표 이동
    for(int i = 0; i < robots_size; i++) {
        x[i] = points[routes[i][0] - 1][0];
        y[i] = points[routes[i][0] - 1][1];
        next_points[point_to_num(x[i], y[i])]++;
    }
    for(pair<int, int> conflict : next_points) {
        if(conflict.second > 1) {
            answer++;
        }
    }
    next_points.clear();
    
    while(out < robots_size) { // 모든 로봇이 탈출할 때까지
        for(int j = 0; j < robots_size; j++) {
            if(robot_out[j])
                continue;
            if(!move_next_point(j, points[routes[j][robot_point[j] + 1] - 1][0], points[routes[j][robot_point[j] + 1] - 1][1])) {
                robot_point[j]++; // 다음 포인트로 이동
                if(robot_point[j] >= routes_size - 1) {
                    robot_out[j] = true; // 탈출
                    out++;
                }
            }
            next_points[point_to_num(x[j], y[j])]++;
        }
        for(pair<int, int> conflict : next_points) {
            if(conflict.second > 1) {
                answer++;
            }
        }
        next_points.clear();
    }
    return answer;
}
