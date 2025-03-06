import java.io.*;
import java.util.*;

public class 강수현_BJ17135 {
	
	static int N, M, D;
	static int map[][] = new int[16][16];
	static boolean visit[][] = new boolean[16][16];
	static int maxCnt;
	static int dx[] = {0, -1, 0}; //좌상우 순서로 탐색
	static int dy[] = {-1, 0, 1};
	static Set<Integer> killPoint = new HashSet<>(); 
	
	static class Point{
		int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static void calcMaxCnt(int k, int s, int point) {
		if(k == 3) { //궁수 조합 생성
			int cnt = 0;
			for(int i = N - 1; i >= 0; i--) { //궁수가 한 줄씩 올라가면서 죽임
				for(int j = 0; j < M; j++) {
					if((point & (1 << j)) != 0) {
						kill(i + 1, j); //죽일 수 있는 적 위치 찾기
						cleanVisit(i);
					}
				}
				cnt += killPoint.size();
				for(int num : killPoint) {
					int x = num / M;
					int y = num % M;
					map[x][y] = 2; //죽인 표시
				}
				killPoint.clear();
			}
			recover();
			maxCnt = Math.max(maxCnt, cnt);
			return;
		}
		for(int i = s; i < M; i++) {
			if((point & (1 << i)) == 0) {
				calcMaxCnt(k + 1, i + 1, point | (1 << i));
			}
		}
	}
	
	static boolean kill(int sx, int sy) {
		Queue<Point> q = new ArrayDeque<>();
		int nx, ny, qSize, b = 0;
		Point cur;
		
		q.offer(new Point(sx, sy));
		while(b < D) { //공격 거리 내로 죽임
			qSize = q.size();
			while(qSize-- > 0) {
				cur = q.poll();
				for(int i = 0; i < 3; i++) {
					nx = cur.x + dx[i];
					ny = cur.y + dy[i];
					if(nx < 0 || nx >= sx || ny < 0 || ny >= M)
						continue;
					if(visit[nx][ny])
						continue;
					q.offer(new Point(nx, ny));
					visit[nx][ny] = true;
					if(map[nx][ny] == 1) { //죽일 수 있는 좌표 담기
						int enc = hash(nx, ny);
						if(!killPoint.contains(enc)) {
							killPoint.add(enc);
						}
						return true;
					}
				}
			}
			b++;
		}
		
		return false;
	}
	
	static int hash(int x, int y) {
		return x * M + y;
	}

	static void cleanVisit(int r) {
		for(int i = r; i >= 0; i--) {
			for(int j = 0; j < M; j++) {
				visit[i][j] = false;
			}
		}
	}
	
	static void recover() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(map[i][j] == 2) //죽인 적을 되살림
					map[i][j] = 1;
			}
		}
	}
	
	static void printVisit() {
		System.out.println("방문 ");
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				System.out.print((visit[i][j]? 1 : 0) + " ");
			}
			System.out.println();
		}
		System.out.println("결과 ");
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		calcMaxCnt(0, 0, 0);
		
		System.out.println(maxCnt);
	}
}
