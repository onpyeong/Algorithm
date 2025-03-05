import java.io.*;
import java.util.*;

public class Solution {

	static int T, N, minDist;
	static int point[][] = new int[13][2];
	static int dist[][] = new int[13][13];
	static boolean visit[] = new boolean[13];

	static void findMinDist(int s, int cnt, int d) {
		if(d >= minDist)
			return;
		if(cnt == N) {
			minDist = Math.min(minDist, d + dist[s][1]); //마지막 정점에서 집까지
			return;
		}
		for(int i = 2; i < N + 2; i++) {
			if(!visit[i]) {
				visit[i] = true;
				findMinDist(i, cnt + 1, d + dist[s][i]);
				visit[i] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N + 2; i++) {
				point[i][0] = Integer.parseInt(st.nextToken());
				point[i][1] = Integer.parseInt(st.nextToken());
				for (int j = 0; j < i; j++) {
					dist[j][i] = Math.abs(point[j][0] - point[i][0]) + Math.abs(point[j][1] - point[i][1]);
					dist[i][j] = dist[j][i];
				}
			}
			
			minDist = 1000;
			findMinDist(0, 0, 0);

			sb.append("#" + t + " " + minDist + "\n");
		}
		System.out.println(sb);

	}

}
