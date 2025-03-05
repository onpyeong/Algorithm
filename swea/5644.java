import java.io.*;
import java.util.*;

public class Solution {
	
	static int T, M, A;
	static int move[][] = new int[2][101];
	static int power[] = new int[8];
	static List<Integer> map[][] = new ArrayList[11][11];
	static boolean visit[][] = new boolean[11][11];
	static int dx[] = {0, 0, 1, 0, -1}; //좌하우상
	static int dy[] = {0, -1, 0, 1, 0};
	
	static class Point{
		int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static void installBC(int sx, int sy, int c, int powerNum) {
		Queue<Point> q = new ArrayDeque<>();
		int nx, ny, qSize, b = 0;
		Point cur;
		
		q.offer(new Point(sx, sy));
		map[sx][sy].add(powerNum); //BC 설치
		visit[sx][sy] = true;
		while(b < c) {
			qSize = q.size();
			while(qSize-- > 0) {
				cur = q.poll();
				for(int i = 1; i <= 4; i++) {
					nx = cur.x + dx[i];
					ny = cur.y + dy[i];
					if(nx < 1 || nx > 10 || ny < 1 || ny > 10)
						continue;
					if(visit[nx][ny])
						continue;
					q.offer(new Point(nx, ny));
					map[nx][ny].add(powerNum); //BC 설치
					visit[nx][ny] = true;
				}
			}
			b++;
		}
		
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j <= 10; j++) {
				visit[i][j] = false;
			}
		}
	}
	
	static int calcMaxPower() {
		int maxPower = 0;
		int ax = 1, ay = 1;
		int bx = 10, by = 10;
		int nax, nay, nbx, nby;
		//초기 위치 power 계산
		int p = 0;
		for(int ap: map[ax][ay]) {
			p = Math.max(p, power[ap]);
		}
		maxPower = p;
		p = 0;
		for(int bp: map[bx][by]) {
			p = Math.max(p, power[bp]);
		}
		maxPower += p;
		for(int i = 0; i < M; i++) { //시간에 따라 이동하면서 점수 계산
			nax = ax + dx[move[0][i]];
			nay = ay + dy[move[0][i]];
			nbx = bx + dx[move[1][i]];
			nby = by + dy[move[1][i]];
			p = 0;
			if(map[nax][nay].isEmpty()) {
				for(int bp: map[nbx][nby]) {
					p = Math.max(p, power[bp]);
				}
			}else if(map[nbx][nby].isEmpty()){
				for(int ap : map[nax][nay]) {
					p = Math.max(p, power[ap]);
				}
			}else{
				for(int ap : map[nax][nay]) {
					for(int bp: map[nbx][nby]) {
						if(ap != bp)
							p = Math.max(p, power[ap] + power[bp]);
						else
							p = Math.max(p, power[ap]);
					}
				}
			}
			ax = nax;
			ay = nay;
			bx = nbx;
			by = nby;
			maxPower += p;
		}
		return maxPower;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int x, y, c, p;
		
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			A = Integer.parseInt(st.nextToken());
			for(int i = 0; i < 2; i++) { //이동 방향 입력
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					move[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int i = 1; i <= 10; i++) {
				for(int j = 1; j <= 10; j++) {
					map[i][j] = new ArrayList<>(8);
				}
			}
			
			for(int i = 0; i < A; i++) { //발전소 설치
				st = new StringTokenizer(br.readLine());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				power[i] = Integer.parseInt(st.nextToken());
				installBC(x, y, c, i);
			}
			sb.append("#" + t + " " + calcMaxPower() + "\n");
		}
		System.out.println(sb);

	}

}
