import java.util.*;
import java.io.*;

class Solution
{
    static int T, N;
    static StringTokenizer st;
    static int[][] a = new int[8][8];
    
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
            sb.append("#" + t + "\n");
            N = Integer.parseInt(br.readLine());
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < N; j++) {
                	a[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            for(int i = 0; i < N; i++) {
                 for(int j = N - 1; j >= 0; j--) {
                     sb.append(a[j][i]); 
                 }
                 sb.append(" ");
                 for(int j = N - 1; j >= 0; j--) {
                     sb.append(a[N - 1 - i][j]); 
                 }
                 sb.append(" ");
                 for(int j = 0; j < N; j++) {
                     sb.append(a[j][N - 1 - i]); 
                 }
                 sb.append("\n");
            }
        }
        System.out.print(sb);
	}
}
