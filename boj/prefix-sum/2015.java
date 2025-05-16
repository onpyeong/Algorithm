import java.util.*;
import java.io.*;

public class Main {
  static int N, K, num;
  static int sum[]; //누적합: 1~i까지의 합
  static Map<Integer, Integer> m = new HashMap<>(); //sum[i] = key의 개수
  static long answer;
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
    
    sum = new int[N + 2];
    m.put(0, 1); //sum[j] == k인 경우 sum[i] - K = 0이므로 m[0] 반환 값은 1이 되어야 함
    st = new StringTokenizer(br.readLine());
    for(int i = 1; i <= N; i++) {
      num = Integer.parseInt(st.nextToken());
      sum[i] = sum[i - 1] + num; //누적합 계산
      answer += m.getOrDefault(sum[i] - K, 0); //sum[j] - K = sum[i] 즉 1~i까지의 합이 sum[j] - K와 일치하는 개수
      m.put(sum[i], m.getOrDefault(sum[i], 0) + 1); //현재 합 개수 세기
    }
    
    System.out.println(answer);
  }
}
