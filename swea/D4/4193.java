import java.util.*;
import java.io.*;

class Solution{
    static int T, N, A, B, C, D, minTime;
    static int[][] area = new int[16][16];
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    public static class Node{
    	private int x, y, time;
        
        Node(int x, int y, int time) {
        	this.x = x;
            this.y = y;
            this.time = time;
        }
    }
    
    static int BFS() {
        visited = new boolean[N + 1][N + 1];
        Queue<Node> q = new LinkedList();
        int x, y, nx, ny, time;
        
        q.offer(new Node(A, B, 0));
        visited[A][B] = true;
        while(!q.isEmpty()) {
       		x = q.peek().x;
            y = q.peek().y;
            time = q.peek().time;
            q.poll();
            if(x == C && y == D) {
            	return time; 
            }
            for(int d = 0; d < 4; d++) {
            	nx = x + dx[d];
                ny = y + dy[d];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if(area[nx][ny] == 1 || visited[nx][ny])
                    continue;
              	if(area[nx][ny] == 0 || time % 3 == 2) {
                	q.offer(new Node(nx, ny, time + 1));
                    visited[nx][ny] = true;
                }
                q.offer(new Node(x, y, time + 1));
            }
        }
    	return -1;
    }
    
	public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        for(int t = 1; t <= T; t++) {
        	N = Integer.parseInt(br.readLine());
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < N; j++) {
                	area[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            C = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            
            minTime = BFS();
            
            sb.append("#" + t + " "+ minTime + "\n");
        }
        System.out.print(sb);
    }
}
