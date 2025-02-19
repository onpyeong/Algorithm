import java.io.*;
import java.util.*;

public class Solution {
	static int T, N, cnt, sz;
	static int a[][] = new int[13][13];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			cnt = 0;
			sz = N;
			
			sb.append("#" + t + "\n");
			for(int i = 0; i < N / 2; i++) {
				for(int j = i; j < sz; j++) {
					a[i][j] = ++cnt;
				}
				for(int j = i + 1; j < sz - 1; j++) {
					a[j][sz - 1] = ++cnt;
				}
				for(int j = sz - 1; j >= i; j--) {
					a[sz - 1][j] = ++cnt;
				}
				for(int j = sz - 2; j >= i + 1; j--) {
					a[j][0] = ++cnt;
				}
				sz = N / 2 + 1;
			}
			if(N % 2 != 0) {
				a[N / 2][N / 2] = ++cnt;
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					sb.append(a[i][j] + " ");
				}
				sb.append("\n");
			}
			
		}
		System.out.println(sb);
	}

}
