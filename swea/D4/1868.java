import java.util.*;
import java.io.*;

class Solution
{
    static int T, N, cnt = 0;
    static char[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    static int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    static String mapStr;
    
    public static class Point{
    	private int x, y;
        public Point(int x, int y) {
        	this.x = x;
            this.y = y;
        }
    }
    
    static void BFS(int sx, int sy) {
        Queue<Point> q = new LinkedList();
        int x, y, nx, ny;
        q.offer(new Point(sx, sy));
        visited[sx][sy] = true;
        while(!q.isEmpty()) {
            x = q.peek().x;
            y = q.peek().y;
            q.poll();
        	for(int d = 0; d < 8; d++) {
            	  nx = x + dx[d];
                ny = y + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if(visited[nx][ny])
                    continue;
                if(map[nx][ny] == '*' || map[nx][ny] != '0') {
                	  visited[nx][ny] = true;
                    continue;
                }
                q.offer(new Point(nx, ny)); //0인 경우에만 계속 탐색
                visited[nx][ny] = true;
            }
        }
    }
    
	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            cnt = 0;
        	N = Integer.parseInt(br.readLine());
            visited = new boolean[N + 1][N + 1];
            map = new char[N + 1][N + 1];
            for(int i = 0; i < N; i++) {
                mapStr = br.readLine();
            	for(int j = 0; j < N; j++) {
                	map[i][j] = mapStr.charAt(j);
                }
            }

            //지뢰 개수 저장
            int ni, nj;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    int starCount = 0;
                    if(map[i][j] == '.') {
                    	for(int d = 0; d < 8; d++) {
                            ni = i + dx[d];
                            nj = j + dy[d];
                            if(ni < 0 || ni >= N || nj < 0 || nj >= N)
                                continue;
                            if(map[ni][nj] == '*') {
                                starCount++;
                            }
                        }
                        map[i][j] = (char) (starCount + '0');
                    }
                }
        	  }
             for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(map[i][j] == '0' && !visited[i][j]) { //0인 지점부터 더 이상 열리지 않을 때까지의 그룹 개수 세기
                        BFS(i, j);
                        cnt++;
                    }
                }
            }
             for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(!visited[i][j] && map[i][j] != '*') { //한 번도 방문하지 않은 숫자 좌표의 개수
                        cnt++;
                    }
                }
            }
            sb.append("#" + t + " " + cnt + "\n");
        }
        System.out.print(sb);
	}
}
