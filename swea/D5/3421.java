import java.util.*;
import java.io.*;

public class Solution {
  
    static int T, N, M, a, b, cnt;
    static int worseSet[] = new int[405];
  
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
      StringBuilder sb = new StringBuilder();
      
      T = Integer.parseInt(br.readLine());
      for(int t = 1; t <= T; t++) {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        cnt = 0; //불가능 조합 수
        if(M != 0) {
          for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;
            worseSet[i] = ((1 << a) | (1 << b)); // 조합 생성
          }
          
          for(int x = 0; x < (1 << N); x++) { //모든 조합에 대하여
            for(int i = 0; i < M; i++) {
              if((x & worseSet[i]) == worseSet[i]) { //패턴이 있으면
                cnt++;
                break;
              }
            }
          }
        }
        sb.append("#" + t + " " + ((1 << N) - cnt) + "\n");
      }
      System.out.println(sb);
  }
}
