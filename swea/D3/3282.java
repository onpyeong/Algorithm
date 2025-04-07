import java.util.*;
import java.io.*;

class  Solution {
    static int T;
	static int N, K;
	static int w[]  = new int[101]; //무게
	static int v[] = new int[101]; //가치
    static int dp[];
    
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            dp = new int[K + 1];
            
            for(int i = 1; i <= N; i++) {
            	st = new StringTokenizer(br.readLine());
                w[i] = Integer.parseInt(st.nextToken());
            	v[i] = Integer.parseInt(st.nextToken());
            }
            
            for(int i = 1; i <= N; i++) {
            	for(int j = K; j >= 1; j--) {
                    if(j - w[i] >= 0) {
                    	dp[j] = Math.max(dp[j], dp[j - w[i]] + v[i]); 
                    }
                }
            }
            sb.append("#").append(t).append(" ").append(dp[K]).append("\n");
        }
		System.out.print(sb);
	}
}
