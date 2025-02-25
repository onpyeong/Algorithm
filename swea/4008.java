import java.util.*;
import java.io.*;

public class Solution {
  
  static int T, N, maxValue, minValue;
  static int num[] = new int[13];
  static int operCnt[] = new int[5]; // + + * /
  static int oper[] = new int[13];
  
  static void calc(int k) { //값복사는 오래 걸림!
    if(k == N - 1) {
      int newValue = num[0];
      for(int i = 0; i < N - 1; i++) {
          if(oper[i] == 0) {
            newValue += num[i + 1];
          }else if(oper[i] == 1) {
            newValue -= num[i + 1];
          }else if(oper[i] == 2) {
            newValue *= num[i + 1];
          }else {
            newValue /= num[i + 1];
          }
      }
      maxValue = Math.max(maxValue, newValue);
      minValue = Math.min(minValue, newValue);
      return;
    }
    for(int i = 0; i < 4; i++) { //11! 동안 방문 체크 4로 줄이기
      if(operCnt[i] > 0) {
        operCnt[i]--;
        oper[k] = i;
        calc(k + 1);
        operCnt[i]++;
      }
    }
  }
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    StringBuilder sb = new StringBuilder();
    
    T = Integer.parseInt(br.readLine());
    for(int t = 1; t <= T; t++) {
      N = Integer.parseInt(br.readLine());
      maxValue = Integer.MIN_VALUE;
      minValue = Integer.MAX_VALUE;
      
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < 4; i++) {
         operCnt[i] = Integer.parseInt(st.nextToken());
      }
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < N; i++) {
        num[i] = Integer.parseInt(st.nextToken());
      }

      calc(0);
      sb.append("#" + t + " " + (maxValue - minValue) + "\n");  
    }
    System.out.println(sb);
  }
}
