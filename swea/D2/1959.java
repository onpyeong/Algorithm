import java.util.*;
import java.io.*;

class Solution
{
    static int T, N, M;
    static StringTokenizer st;
    static int[] a = new int[21];
    static int[] b = new int[21];
    static int sum, maxSum;
    
	public static void main(String args[]) throws Exception
	{
		    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            if(N <= M) {
                st = new StringTokenizer(br.readLine());
            	for(int i = 0; i < N; i++) {
                	a[i] = Integer.parseInt(st.nextToken());
                }
                st = new StringTokenizer(br.readLine());
                for(int i = 0; i < M; i++) {
                	b[i] = Integer.parseInt(st.nextToken());
                }
            }else {
            	st = new StringTokenizer(br.readLine());
            	for(int i = 0; i < N; i++) {
                	b[i] = Integer.parseInt(st.nextToken());
                }
                st = new StringTokenizer(br.readLine());
                for(int i = 0; i < M; i++) {
                	a[i] = Integer.parseInt(st.nextToken());
                }
                int tmp;
                tmp = N;
                N = M;
                M = tmp;
            }
            maxSum = 0;
            for(int j = 0; j + N <= M; j++) {
                sum = 0;
                for(int i = 0; i < N; i++) {
                    sum += a[i] * b[j + i];
                }
                maxSum = Math.max(maxSum, sum);
            }
            sb.append("#" + t + " " + maxSum + "\n");
        }
        System.out.print(sb);
	}
}
