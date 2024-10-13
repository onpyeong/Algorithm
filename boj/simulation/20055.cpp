#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int p;
queue<int> up, down, robots;
int power[201];
bool hasRobot[201];
int cnt, level;
int upPoint, downPoint;

void rotate() {
    upPoint = down.front();
    down.push(up.front());
    up.push(upPoint);
    up.pop();
    down.pop();
    downPoint = up.front();
    if(!robots.empty() && robots.front() == downPoint) {
        robots.pop();
        hasRobot[downPoint] = false;
    }
}

void moveRovot() {
    int robotSize = robots.size();
    for(int i = 0; i < robotSize; i++) {
        int r = robots.front();
        robots.pop();
        hasRobot[r] = false;
        
        int nxtRobot = (r + 1) % (2 * N);
        if(nxtRobot == 0) nxtRobot = 2 * N;

        if(!hasRobot[nxtRobot] && power[nxtRobot] >= 1) {
            power[nxtRobot]--;
            if(power[nxtRobot] == 0)
                cnt++;
            if(downPoint == nxtRobot) {
                continue;
            }
            robots.push(nxtRobot);
            hasRobot[nxtRobot] = true;
        }else {
            robots.push(r);
            hasRobot[r] = true;
        }
    }
}

void putRovot() {
    if(power[upPoint] > 0){
        power[upPoint]--;
        if(power[upPoint] == 0)
            cnt++;
        robots.push(upPoint);
        hasRobot[upPoint] = true;
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= 2 * N; i++) {
        cin >> p;
        power[i] = p;
    }
    for(int i = N; i >= 1; i--) {
        up.push(i);
    }
    for(int i = 2 * N; i > N; i--) {
        down.push(i);
    }
   
    while(true) {
        level++;
        
        rotate();
        moveRovot();
        putRovot();
        
        if(cnt >= K){
            break;
        }
    }
    
    cout << level;

    return 0;
}
