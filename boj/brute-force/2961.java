import java.util.*;
import java.io.*;

public class Main {
  
    static int N, ans = Integer.MAX_VALUE;
    static int s[] = new int[12];
    static int b[] = new int[12];
    
    static void findMinTaste() {
      for(int x = 0; x < (1 << N); x++) {
        int ps = 1, pb = 0;
        for(int i = 0; i < N; i++) {
          if((x & (1 << i)) != 0) {
            ans = Math.min(ans, Math.abs(ps * s[i] - pb - b[i])); 
            ps *= s[i];
            pb += b[i];
          }
        }
      }
    }
  
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;

      N = Integer.parseInt(br.readLine());
      for(int i = 0; i < N; i++) {
        st = new StringTokenizer(br.readLine());
        s[i] = Integer.parseInt(st.nextToken());
        b[i] = Integer.parseInt(st.nextToken());
      }
      findMinTaste();
      System.out.println(ans);
    } 
}
