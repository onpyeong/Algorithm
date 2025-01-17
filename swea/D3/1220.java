import java.util.*;
import java.io.*;

class Solution
{
    static int N, cnt;
    static int map[][] = new int[101][101];
    
	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        
		for(int t = 1; t <= 10; t++) {
          cnt = 0;
        	N = Integer.parseInt(br.readLine());
            
            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
            	for(int j = 0; j < N; j++) {
                	map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            for(int j = 0; j < N; j++) {
                boolean isOne = false;
            	for(int i = 0; i < N; i++) {
                	if(map[i][j] == 1) {
                    	isOne = true;
                    }
                    if(isOne && map[i][j] == 2) {
                    	cnt++;
                        isOne = false;
                    } 
                }
            }
            sb.append("#" + t + " " + cnt + "\n");
        }
        System.out.print(sb);
	}
}
