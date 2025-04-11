import java.io.*;
import java.util.*;

public class Solution {
	
	static int T, N, W, H;
	static int map[][] = new int[16][13];
	static int temp[][] = new int[16][13];
	static int point[] = new int[5];
	static boolean visit[][];
	static int minCnt;
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	
	static class Brick {
		int x;
		int y;

		public Brick(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static void copyMapToTemp() {
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				temp[i][j] = map[i][j];
			}
		}
	}
	
	static void calcMaxScore(int k) {
		if(k == N) {
			copyMapToTemp();
			for(int i = 0; i < N; i++) {
				breakBrick(point[i]);
			}

			int cnt = 0;
			for(int i = 0; i < H; i++) {
				for(int j = 0; j < W; j++) {
					if(temp[i][j] != 0)
						cnt++;
				}
			}
			minCnt = Math.min(minCnt, cnt);
			return;
		}
		for(int i = 0; i < W; i++) {
			point[k] = i;
			calcMaxScore(k + 1);
		}
	}
	
	static void breakBrick(int c) {
		Queue<Brick> q = new ArrayDeque<>();
		visit = new boolean[H + 1][W + 1];
		int sx, sy, x, y, nx, ny;
		Brick cur;
		int r;
		for(r = 0; r < H; r++) {
			if(temp[r][c] != 0) {
				break;
			}
		}
		if(r == H) { //벽돌이 없으면
			return;
		}
		if(temp[r][c] <= 1) {
			temp[r][c] = 0;
			return;
		}
		sx = r;
		sy = c;
		q.offer(new Brick(sx, sy));
		visit[sx][sy] = true;
		while(!q.isEmpty()) {
			cur = q.poll();
			for(int i = 0; i < 4; i++) {
				x = cur.x;
				y = cur.y;
				for(int j = 0; j < temp[cur.x][cur.y] - 1; j++) {
					nx = x + dx[i];
					ny = y + dy[i];
					if(nx < 0 || nx >= H || ny < 0 || ny >= W)
						break;
					x = nx;
					y = ny;
					if(visit[nx][ny])
						continue;
					if(temp[nx][ny] <= 1) {
						visit[nx][ny] = true;
						continue;
					}
					q.offer(new Brick(nx, ny));
					visit[nx][ny] = true;
				}
			}
		
		}
		
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(visit[i][j])
					temp[i][j] = 0;
			}
		}
		//중력이 작용한다.
		gravity();
	}
	
	static void gravity() {
		int emptyX, brickX;
		for(int i = 0; i < W; i++) {
			emptyX = H - 1;
			brickX = emptyX;
			while(emptyX >= 0 && brickX >= 0) {
				while(brickX >= 0 && temp[brickX][i] == 0) {
					brickX--;
				}
				if(brickX == -1)
					break;
				if(brickX != emptyX) {
					temp[emptyX][i] = temp[brickX][i];
					temp[brickX][i] = 0;
				}
				emptyX--;
				brickX--;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            minCnt = 400;
            for(int i = 0; i < H; i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < W; j++) {
            		map[i][j] = Integer.parseInt(st.nextToken());
            	}
            }

            calcMaxScore(0);
            sb.append("#").append(t).append(" ").append(minCnt).append("\n");
        }
        System.out.print(sb);
    }
}
