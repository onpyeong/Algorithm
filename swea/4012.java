import java.util.*;
import java.io.*;

public class Solution {
  
  static int T, N, add, aSum, bSum, minDiff;
  static int synergy[][] = new int[17][17];
  static int aFoodCombi[] = new int[9];
  static boolean aFoodCheck[];
  static int bFoodCombi[] = new int[9];
  
  static void makeCombi(int k, int s) {
    if(k == N / 2) {
      int idx = 0;
      for(int i = 0; i < N; i++) {
        if(!aFoodCheck[i]) {
          bFoodCombi[idx++] = i;
        }
      }
      aSum = bSum = 0;
      for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
          aSum += synergy[aFoodCombi[i]][aFoodCombi[j]];
          bSum += synergy[bFoodCombi[i]][bFoodCombi[j]];
        }
      }
      minDiff = Math.min(minDiff, Math.abs(aSum - bSum));
      return;
    }
    for(int i = s; i < N; i++) {
      aFoodCombi[k] = i;
      aFoodCheck[i] = true;
      makeCombi(k + 1, i + 1);
      aFoodCheck[i] = false;
    }
  }
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    StringBuilder sb = new StringBuilder();
    
    T = Integer.parseInt(br.readLine());
    for(int t = 1; t <= T; t++) {
      N = Integer.parseInt(br.readLine());
      aFoodCheck = new boolean[N + 1];
      for(int i = 0; i < N; i++) {
        st = new StringTokenizer(br.readLine());
        for(int j = 0; j < N; j++) {
          synergy[i][j] = Integer.parseInt(st.nextToken());
        }
      }
      minDiff = Integer.MAX_VALUE;
      makeCombi(0, 0);
    
      sb.append("#" + t + " " + minDiff + "\n");  
    }
    System.out.print(sb);
  }
}
