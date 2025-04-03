import java.io.*;
import java.util.*;

public class Solution {
    
    static int T;
    static int N, M;
    static int totalHome;
    static int installCost[] = new int[41];
    static int map[][] = new int[21][21];
    static boolean visit[][];
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, 1, 0, -1};
    
    static class Pair{
        int x;
        int y;
        
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int calcMaxCost() {
      int maxCost = 0, maxHome = 0;
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          visit = new boolean[N + 1][N + 1];
          Queue<Pair> q = new ArrayDeque<>();
          Pair p;
          int nx, ny;
          int house = 0;
            
          q.offer(new Pair(i, j));
          visit[i][j] = true;
          if(map[i][j] == 1) {
        	  house++;
        	  if(maxHome <= house) {
        		  maxHome = house;
            	  maxCost = Math.max(maxCost, house * M - installCost[1]);
        	  }
          }
          int d = 2;
          while(d < N * 2) {
            int qSize = q.size();
            while(qSize-- > 0) {
              p = q.poll();
              for(int k = 0; k < 4; k++) {
                nx = p.x + dx[k];
                ny = p.y + dy[k];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                  continue;
                if(visit[nx][ny])
                  continue;
                q.offer(new Pair(nx, ny));
                visit[nx][ny] = true;
                if(map[nx][ny] == 1) {
                  house++;
                }
              }
            }
           
            if(maxHome < house && house * M - installCost[d] >= 0) {
            	maxHome = house;
            	maxCost = house * M - installCost[d];
            }else if(maxHome == house) {
            	maxCost = Math.max(maxCost, house * M - installCost[d]);
            }
            if(totalHome == house)
                break;
            d++;
          }
          
        }
      }
      return maxHome;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        for(int i = 1; i <= 40; i++) {
        	installCost[i] = i * i + (i - 1) * (i - 1);
        }

        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            totalHome = 0;
            st = new StringTokenizer(br.readLine());        
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());    
                for(int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if(map[i][j] == 1)
                        totalHome++;
                }
            }
            
            sb.append("#").append(t).append(" ").append(calcMaxCost()).append("\n");
        }
        System.out.print(sb);
    }
}
