import java.util.*;
import java.io.*;

class Solution
{
    static int T, N, M, R, C, L, cnt;
    static int map[][] = new int[51][51];
    static boolean visited[][];
    static int dx[] = {-1, 1, 0, 0}; //상하좌우
    static int dy[] = {0, 0, -1, 1};
    static boolean structure[][] = {{false, false, false, false}, //파이프 구조에 따라 상하좌우로 이동가능한지 여부
                                    {true, true, true, true},
                                    {true, true, false, false},
                                    {false, false, true, true},
                                    {true, false, false, true},
                                    {false, true, false, true},
                                    {false, true, true, false},
                                    {true, false, true, false}};
    
    public static class Point{
    	private int x, y, l;
        public Point(int x, int y, int l) {
        	this.x = x;
            this.y = y;
            this.l = l;
        }
    }
    
    static void BFS() {
    	  Queue<Point> q = new LinkedList();
        int x, y, l, structureNum;
        int nx, ny;
        
        q.offer(new Point(R, C, 1));
        visited[R][C] = true;
        while(!q.isEmpty()) {
        	Point p = q.peek();
            x = p.x;
            y = p.y;
            l = p.l;
            if(l == L + 1) {
            	break;
            }
            q.poll();
            structureNum = map[x][y];
            cnt++;
            for(int d = 0; d < 4; d++) {
            	if(structure[structureNum][d]) {
                	nx = x + dx[d];
                    ny = y + dy[d];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if(map[nx][ny] == 0 || visited[nx][ny])
                        continue;
                    if(d < 2 && !structure[map[nx][ny]][1 - d]) // 상하 서로 연결되어 있는지
                        continue;
                    if(d >= 2 && !structure[map[nx][ny]][5 - d]) //좌우 서로 연결되어 있는지
                        continue;
                    q.offer(new Point(nx, ny, l + 1));
                    visited[nx][ny] = true;
                }
            }
        }
    }
    
    
	public static void main(String args[]) throws Exception
	{
		    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            cnt = 0;
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            visited = new boolean[N + 1][M + 1];
            
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < M; j++) {
                	map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
 
            BFS();
            sb.append("#" + t + " " + cnt + "\n");
        }
        System.out.print(sb);
	}
}
