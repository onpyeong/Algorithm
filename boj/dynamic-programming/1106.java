/*
// 중복 계산 없앤 버전
for(int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      cost[i] = Integer.parseInt(st.nextToken());
      people[i] = Integer.parseInt(st.nextToken());
    }
    
    for(int i = 0; i <= minPeopleCnt; i++) {
      dp[1][i] = cost[1] * (i / people[1]);
      if(i % people[1] != 0) {
        dp[1][i] += cost[1];
      }
    }
    
    for(int i = 2; i <= N; i++) {
      for(int j = 0; j <= minPeopleCnt; j++) {
        dp[i][j] = dp[i - 1][j];
        
        int prevJ = Math.max(0, j - people[i]);
        dp[i][j] = Math.min(dp[i - 1][prevJ] + cost[i], dp[i][j]);
        dp[i][j] = Math.min(dp[i][prevJ] + cost[i], dp[i][j]);
      }
    }
// 1차원 dp로도 풀 수 있음

        int[] cost = new int[N];
        int[] people = new int[N];
        int maxPeoplePerCity = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            people[i] = Integer.parseInt(st.nextToken());
            maxPeoplePerCity = Math.max(maxPeoplePerCity, people[i]);
        }

        final int INF = 1_000_000_000;
        int maxPeople = C + maxPeoplePerCity; // 목표 이상을 위해 약간 여유
        int[] dp = new int[maxPeople + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = people[i]; j <= maxPeople; j++) {
                dp[j] = Math.min(dp[j], dp[j - people[i]] + cost[i]);
            }
        }

        int ans = INF;
        for (int i = C; i <= maxPeople; i++) ans = Math.min(ans, dp[i]);
        System.out.println(ans);
*/
import java.util.*;
import java.io.*;

public class Main {
  static int minPeopleCnt, N;
  static int cost[];
  static int people[];
  static int dp[][];
  
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    
    st = new StringTokenizer(br.readLine());
    minPeopleCnt = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());
    
    cost = new int[N + 1];
    people = new int[N + 1];
    dp = new int[N + 1][minPeopleCnt + 1];
    
    for(int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      cost[i] = Integer.parseInt(st.nextToken());
      people[i] = Integer.parseInt(st.nextToken());
    }
    
    for(int i = 0; i <= minPeopleCnt; i++) {
      dp[0][i] = cost[0] * (i / people[0]);
      if(i % people[0] != 0) {
        dp[0][i] += cost[0];
      }
    }
    
    for(int i = 1; i < N; i++) {
      for(int j = 0; j <= minPeopleCnt; j++) {
        // 내 이전 도시 투자에서의 최소 비용
        dp[i][j] = dp[i - 1][j];
        // 내 이전 도시에서 내 도시를 투자하지 않았을 때의 비용 + 내 도시 투자 비용
        if(j - people[i] >= 0) {
          dp[i][j] = Math.min(dp[i - 1][j - people[i]] + cost[i], dp[i][j]);
          // 내 도시를 투자하지 않았을 때 또 투자
          dp[i][j] = Math.min(dp[i][j - people[i]] + cost[i], dp[i][j]);
        }else {
          dp[i][j] = Math.min(dp[i - 1][0] + cost[i], dp[i][j]);
          dp[i][j] = Math.min(dp[i][0] + cost[i], dp[i][j]);
        }
      }
    }

    System.out.println(dp[N - 1][minPeopleCnt]);
    
  }
}
