import java.util.*;
import java.io.*;

public class Main {
  
    static int N;
    
    static int num[] = new int[10];
    static int primeNum[] = {2, 3, 5, 7};
    static int possNum[] = {1, 3, 5, 7, 9};
    static StringBuilder sb = new StringBuilder();
    
    static void makePrimeNum(int k, int p) {
      if(k == N) {
        sb.append(p + "\n");
        return;
      }
      for(int i = 0; i < 5; i++) {
        if(!isPrime(p * 10 + possNum[i])) {
          continue;
        }
        makePrimeNum(k + 1, p * 10 + possNum[i]);
      }
    }
    
    static boolean isPrime(int p) {
      for(int i = 2; i * i <= p; i++) {
        if(p % i == 0) {
          return false;
        }
      }
      return true;
    }
  
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;

      N = Integer.parseInt(br.readLine());
      for(int i = 0; i < 4; i++) {
        num[0] = primeNum[i];
        makePrimeNum(1, num[0]);
      }
      System.out.println(sb);
    } 
}
