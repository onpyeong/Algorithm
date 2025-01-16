import java.util.*;
import java.io.*;

public class Solution {
    static int T, N, B, maxSum, answer;
    static int height[] = new int[21];
    
	public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            answer = 2000000;
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++) {
            	height[i] = Integer.parseInt(st.nextToken());
            }

            int sum;
            for(int x = 0; x < Math.pow(2, N + 1); x++) {               
                sum = 0;
                for(int i = 0; i < N; i++) {
                    if((x & (1 << i)) == (1 << i)) {
						sum += height[i];
                    }
                }
                if(sum >= B) {
                    answer = Math.min(answer, sum);
                }
            }
        	sb.append("#" + t + " " + (answer - B) + '\n');
        }
        System.out.print(sb);
    }
}
