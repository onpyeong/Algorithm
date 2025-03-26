import java.util.*;
import java.io.*;


public class Solution {

	static int T = 10;
	static int N, S;
	static boolean adj[][];
	static boolean visit[];

	public static int call() {
		Queue<Integer> q = new ArrayDeque<>();
		int x = 0, qSize, maxNum = -1, ans = -1;
		
		q.offer(S);
		visit[S] = true;
		while(!q.isEmpty()) {
			qSize = q.size();
			maxNum = -1;
			while(qSize-- > 0) {
				x = q.poll();
				for(int i = 1; i <= 100; i++) {
					if(adj[x][i] && !visit[i]) {
						q.offer(i);
						visit[i] = true;
						maxNum = Math.max(maxNum, i);
					}
				}
			}
			if(maxNum != -1) {
				ans = maxNum;
			}
		}
		
		return ans;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int from, to;
		
		for(int t = 1; t <= 10; t++) {
			adj = new boolean[103][103];
			visit = new boolean[103];
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			S = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N / 2; i++) {
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				adj[from][to] = true;
			}

			System.out.println("#" + t + " " + call());
		}
	}

}
