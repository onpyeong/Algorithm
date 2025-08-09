import java.util.*;
import java.io.*;

public class Main {
  
  static int N, day;
  static int[] temp = new int[100005];
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    
    st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    day = Integer.parseInt(st.nextToken());
    
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < N; i++) {
      temp[i] = Integer.parseInt(st.nextToken());
    }
    
    int s = 0, e = 0 + day - 1;
    int max_sum = 0;
    for(int i = s; i <= e; i++) {
      max_sum += temp[i];
    }
    int sum = max_sum;
    while(e <= N - 2) {
      sum = sum - temp[s] + temp[e + 1];
      if(max_sum < sum) {
        max_sum = sum;
      }
      s++;
      e++;
    }
    
    System.out.println(max_sum);
    
  }
}
