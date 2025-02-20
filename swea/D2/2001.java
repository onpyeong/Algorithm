import java.util.*;
import java.io.*;

class Solution {
    
    static int T, N, M;
    static int map[][] = new int[17][17];
    
    static int countMaxFly() {
    	int fly, maxFly = 0;
        for(int i = 0; i <= N - M; i++) {
            for(int j = 0; j <= N - M; j++) {
                fly = 0;
                for(int x = i; x < i + M; x++) {
                	for(int y = j; y < j + M; y++) {
                    	fly += map[x][y];
                    }
                }
                maxFly = Math.max(maxFly, fly);
            }
        }
        return maxFly;
    }
    
	public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
        	
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
                	map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            sb.append("#" + t + " " + countMaxFly() + "\n");
        }
        System.out.println(sb);
    }
}
