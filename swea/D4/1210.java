import java.io.*;
import java.util.*;

public class Solution {
	static int T, N, sz = 100, endX, endY;
	static int map[][] = new int[105][105];
	static int dx[] = {-1, 0, 0};
	static int dy[] = {0, -1, 1};
	
	static int findStart() {
		int x = endX, y = endY;
		boolean isLeft;
		while(x >= 0) {
			isLeft = false;
			while(y - 1 >= 0 && map[x][y - 1] == 1) {
				y--;
				isLeft = true;
			}
			if(!isLeft) {
				while(y + 1 < sz && map[x][y + 1] == 1) {
					y++;
				}
			}
			x--;
		}
		return y;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = 10;
		for(int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			for(int i = 0; i < sz; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < sz; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if(map[i][j] == 2) {
						endX = i;
						endY = j;
					}
				}
			}
			sb.append("#" + t + " " + findStart() + "\n");
		}
		System.out.println(sb);
	}

}
