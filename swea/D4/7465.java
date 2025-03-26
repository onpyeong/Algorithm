import java.io.*;
import java.util.*;

public class Solution {
	
	static int T;
	static int N, M;
	static int cnt;
	static int p[];
	
	static int find(int x) {
		if(p[x] == x)
			return x;
		return p[x] = find(p[x]);
	}
	
	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		if(a <= b) {
			p[b] = a;
		}else {
			p[a] = b;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int a, b;
		
		T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			p = new int[N + 2];
			for(int i = 1; i <= N; i++) {
				p[i] = i;
			}
			
			for(int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				if(find(a) != find(b)) {
					union(a, b);
				}
			}
			
			for(int i = 1; i <= N; i++) {
				find(i);
			}

			Set<Integer> group = new HashSet<Integer>();
			for(int i = 1; i <= N; i++) {
				group.add(p[i]);
			}
            sb.append("#").append(t).append(" ").append(group.size()).append("\n");
		}
        System.out.print(sb);
	}

}
