import java.util.*;
import java.io.*;

public class Solution {
    static int T, N, answer, max;
    static int height[] = new int[105]; 
    
    public static void f() {
      int odd = 0, even = 0;
      for(int i = 0; i < N; i++) {
          int diff = max - height[i];
          if(diff == 0)
              continue;
          even += diff / 2;
          odd += diff % 2;
      }
      
      answer = odd + even; //
      if(odd < even) {
				int remainEven = (even - odd) * 2; //남는 짝수날 수
				int zipEven = (remainEven / 3) * 2; //짝수날 3개를 묶으면 홀+짝 2개로 줄일 수 있음 => 020202 => 1212
				
				if(remainEven % 3 == 2) { // 압축 후 남은 날짜가 짝수 날이면 추가로 2일 더함
					zipEven += 2;
				} else if (remainEven % 3 == 1) 
                    zipEven += 1; // 남은 날짜가 홀수 날이면 1일 더함
				
				answer = (odd * 2) + zipEven; // 최종 결과 계산
			} else if (odd - even > 1){ // 홀수 날짜가 더 많을 경우
				answer += (odd - even - 1); //이미 위에서 홀짝 더해줬으니까 odd의 빈칸 쉬는날의 개수를 더해준다! -> -1은 홀수날 하나는 기본으로 쉬는날 없이 더할 수 있어서
			}
    }
    
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
      StringBuilder sb = new StringBuilder();
      
      T = Integer.parseInt(br.readLine());
      for(int t = 1; t <= T; t++) {
        N = Integer.parseInt(br.readLine());
        max = -1;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
          height[i] = Integer.parseInt(st.nextToken());
          max = Math.max(height[i], max);
        }
        f();
        sb.append("#" + t + " " + answer +"\n");
      }
      System.out.println(sb);
    }
}
