import java.io.*;
import java.util.*;

public class Main {
	
	static int N, M;
	static boolean status[][] = new boolean[11][11];
	static int islandNum = 1;
	static int map[][] = new int[11][11];
	static int d[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	static ArrayList<Bridge> bList = new ArrayList<>(); 
	static int p[];
	
	static class Point{
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static class Bridge{
		int s;
		int e;
		int len;
		
		public Bridge(int s, int e, int len) {
			this.s = s;
			this.e = e;
			this.len = len;
		}
	}
	
	static void bfs(int sx, int sy, int num) {
		Queue<Point> q = new ArrayDeque<>();
		Point cur;
		int nx, ny;
		
		q.offer(new Point(sx, sy));
		map[sx][sy] = num;
		while(!q.isEmpty()) {
			cur = q.poll();
			for(int i = 0; i < 4; i++) {
				nx = cur.x + d[i][0];
				ny = cur.y + d[i][1];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				if(map[nx][ny] != -1)
					continue;
				q.offer(new Point(nx, ny));
				map[nx][ny] = num;
			}
		}
	}
	
	static void makeIslandNum() {
		//모든 지도에서 bfs돌려서 지도 번호로 채우기
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(map[i][j] == -1) {
					bfs(i, j, islandNum++);
				}
			}
		}
	}
	
	static void calcTotalBridge() {
		int si, ei;
		//가로 다리 추가
		for(int i = 0; i < N; i++) {
			int len = 0;
			si = ei = -1;
			for(int j = 0; j < M; j++) {
				if(map[i][j] >= 1) {
					ei = map[i][j];
					if(si != -1 && len > 1) {
						bList.add(new Bridge(si, ei, len));
					}else {
						si = ei;
					}
					len = 0;
					continue;
				}
				if(map[i][j] == 0) {
					len++;
				}
			}
		}
		//세로 다리 추가
		for(int i = 0; i < M; i++) {
			int len = 0;
			si = ei = -1;
			for(int j = 0; j < N; j++) {
				if(map[j][i] >= 1) {
					ei = map[j][i];
					if(si != -1 && len > 1) {
						bList.add(new Bridge(si, ei, len));
					}else {
						si = ei;
					}
					len = 0;
					continue;
				}
				if(map[j][i] == 0) {
					len++;
				}
			}
		}
	}
	
	static int find(int x) {
		if(x == p[x])
			return x;
		return p[x] = find(p[x]);
	}
	
	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		if(a < b)
			p[a] = b;
		else
			p[b] = a;
	}

	
	static int mst() {
		if(bList.size() == 0)
			return -1;
		bList.sort((a, b) -> a.len - b.len);
		
		islandNum--;
		p = new int[islandNum + 1];
		for(int i = 1; i <= islandNum; i++) {
			p[i] = i;
		}
		
		int bSize = bList.size();
		int totalLen = 0;
		int connect = 0;
		for(int i = 0; i < bSize; i++) {
			if(find(bList.get(i).s) != find(bList.get(i).e)) {
				union(bList.get(i).s, bList.get(i).e);
				totalLen += bList.get(i).len;
				connect++;
			}
		}
		if(connect < islandNum - 1)
			return -1;
		return totalLen;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				status[i][j] = st.nextToken().equals("1") ? true : false;
				if(status[i][j])
					map[i][j] = -1;
			}
		}
		
		makeIslandNum();
		calcTotalBridge();
		System.out.println(mst());
	}
}
