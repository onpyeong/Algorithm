import java.io.*;
import java.util.*;

public class 강수현_7733 {
	
	static int T, N;
	static int score[][] = new int[101][101];
	static boolean visit[][] = new boolean[101][101];
	static int dx[] = {-1, 1, 0, 0};
	static int dy[] = {0, 0, -1, 1};
	
	
	static class Point{
		int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static void bfs(int sx, int sy) {
		Queue<Point> q = new ArrayDeque<>();
		int nx, ny;
		Point cur;
		
		q.offer(new Point(sx, sy));
		visit[sx][sy] = true;
		while(!q.isEmpty()) {
			cur = q.poll();
			for(int i = 0; i < 4; i++) {
				nx = cur.x + dx[i];
				ny = cur.y + dy[i];
				if(nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if(visit[nx][ny])
					continue;
				q.offer(new Point(nx, ny));
				visit[nx][ny] = true;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			int maxScore = 0;
			N = Integer.parseInt(br.readLine());
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					score[i][j] = Integer.parseInt(st.nextToken());
					if(maxScore < score[i][j])
						maxScore = score[i][j];
				}
			}
			
			int maxCnt = 1; //치즈를 먹지 않은 경우 무조건 1 덩어리
			for(int i = 1; i < maxScore; i++) {
				int cnt = 0;
				for(int j = 0; j < N; j++) {
					for(int k = 0; k < N; k++) {
						if(score[j][k] <= i) {
							visit[j][k] = true;
						}
					}
				}
				for(int j = 0; j < N; j++) {
					for(int k = 0; k < N; k++) {
						if(!visit[j][k]) {
							bfs(j, k);
							cnt++;
						}
					}
				}
				for(int j = 0; j < N; j++) {
					for(int k = 0; k < N; k++) {
						visit[j][k] = false;
					}
				}
				maxCnt = Math.max(maxCnt, cnt);
			}
			
			sb.append("#" + t + " " + maxCnt + "\n");
		}
		System.out.println(sb);

	}


}
