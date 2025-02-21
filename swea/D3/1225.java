import java.util.*;
import java.io.*;

public class Solution {
  
    static int T = 10, m;
    static int num[] = new int[10];
    
    static int makePassword(int start) {
      int idx = 0;
      while(true) {
         for(int i = 0; i < 5; i++) {
          idx = (start + i) % 8;
          if(num[idx] <= i + 1) {
            num[idx] = 0;
            return (idx + 1) % 8;
          }
          num[idx] -= i + 1;
        }
        start = (idx + 1) % 8;
      }
    }
  
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
      StringBuilder sb = new StringBuilder();
      
      for(int t = 1; t <= T; t++) {
        m = Integer.MAX_VALUE;
        br.readLine();
        sb.append("#" + t + " ");
        st = new StringTokenizer(br.readLine());
        
        int startIdx = -1;
        int idx, start = 0;
        for(int n = 0; n < 8; n++) {
          num[n] = Integer.parseInt(st.nextToken());
          if(num[n] == 0 && startIdx == -1) {
            startIdx = n;
          }else if(m > num[n] / 15) {
            m = num[n] / 15;
          }
        }
        
        if(startIdx != -1) {
          start = startIdx + 1;
        }else{
         if(m > 1) {
           int s = 15 * (m - 1);
          for(int n = 0; n < 8; n++) {
            num[n] -= s;
          }
         }
          start = makePassword(0);
        }
        
        for(int i = 0; i < 8; i++) {
          idx = (start + i) % 8;
          sb.append(num[idx] + " ");
        }
        sb.append("\n");
      }
      System.out.println(sb);
  }
}
