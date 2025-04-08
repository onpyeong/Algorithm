import java.io.*;
import java.util.*;
 
public class Solution {
     
    static int T;
    static int N;
    static int map[][] = new int[101][101];
    static int maxScore, maxWormhole;
    static final int BLACKHOLE = -1;
    static Pair wormhole[][];
    static int wormholeCnt;
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, 1, 0, -1};
    static int changeDir[][] = {
            {-1, -1, -1, -1},
            {2, 3, 1, 0},
            {1, 3, 0, 2},
            {3, 2, 0, 1},
            {2, 0, 3, 1},
            {2, 3, 0, 1}
    };
     
    static class Pair{
        int x;
        int y;
         
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
     
    static int startGame(int sx, int sy, int dir) {
        int score = 0;
        int x = sx, y = sy, nx, ny;
        while(true) {
            nx = x + dx[dir];
            ny = y + dy[dir];
            //시작 좌표이면 종료
            if(nx == sx && ny == sy)
                break;
            //범위 벗어나면 반대방향으로 바꾸고 좌표 이동
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                dir = (dir + 2) % 4;
                score = score * 2 + 1;
                break;
            }
            //만약 BLACKHOLE 종료
            if(map[nx][ny] == BLACKHOLE)
                break;
            if(map[nx][ny] >= 6 && map[nx][ny] <= 10) {
                //웜홀이면 다른 웜홀 좌표로 이동
                int wNum = map[nx][ny] - 6;
                Pair w;
                int i;
                for(i = 0; i < 2; i++) {
                    w = wormhole[wNum][i];
                    if(w.x == nx && w.y == ny) {
                        break;
                    }
                }
                //반대 좌표로 바꾸기!
                x = wormhole[wNum][1 - i].x;
                y = wormhole[wNum][1 - i].y;
                continue;
            }
            //블록이면 1 ~ 5 방향을 바꾸고 좌표 이동
            if(map[nx][ny] >= 1 && map[nx][ny] <= 5) {
                int cDir = changeDir[map[nx][ny]][dir];
                if(cDir == (dir + 2) % 4) {
                    score = score * 2 + 1;
                    break;
                }
                dir = cDir;
                score++;
            }
            //만약 0이면 다음 좌표로 이동  
            x = nx;
            y = ny;
        }
        return score;
    }
     
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
 
        T = Integer.parseInt(br.readLine().trim());
        for (int t = 1; t <= T; t++) {
            maxScore = 0;
            wormhole = new Pair[6][2];
            wormholeCnt = 0;
            maxWormhole = 0;
            N = Integer.parseInt(br.readLine().trim());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine().trim());    
                for(int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if(map[i][j] >= 6 && map[i][j] <= 10) {
                        int k = map[i][j] - 6;
                        maxWormhole = Math.max(maxWormhole, k);
                        if(wormhole[k][0] == null)
                            wormhole[k][0] = new Pair(i, j);
                        else {
                            wormhole[k][1] = new Pair(i, j);
                            wormholeCnt++;
                        }
                    }
                }
            }
 
            for (int i = 0; i < N; i++) {   
                for(int j = 0; j < N; j++) {
                    if(map[i][j] == 0) {
                        for(int d = 0; d < 4; d++) {
                            maxScore = Math.max(maxScore, startGame(i, j, d));
                        }
                    }
                }
            }
     
            sb.append("#").append(t).append(" ").append(maxScore).append("\n");
        }
        System.out.print(sb);
    }
}
