import java.util.*;
import java.io.*;

public class 강수현_2115 {

	static int T;
	static int N, M, C;
	static int price, maxPrice;
	static int a[][] = new int[11][11];
	
	static int calcMaxPrice(int x, int y) { //벌통 내에서 부분집합으로 최대 비용 계산
        int temp[] = Arrays.copyOfRange(a[x], y, y + M);
        int weight, cost, maxCost = 0;
        for(int b = 1; b < Math.pow(2, M); b++) {
        	weight = 0;
        	for(int i = 0; i < M; i++) {
        		if((b & (1 << i)) != 0) {
        			weight += temp[i];
        		}
        	}
        	if(weight <= C) {
        		cost = 0;
				for(int i = 0; i < M; i++) {
	        		if((b & (1 << i)) != 0) {
	        			cost += temp[i] * temp[i];
	        		}
	        	}
				maxCost = Math.max(maxCost, cost);
        	}
        }
        		
		return maxCost;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			maxPrice = 0;
			
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					a[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			for(int fi = 0; fi < N; fi++) {
				for(int fj = 0; fj + M <= N; fj++) { //처음 벌통 시작 위치
					for(int si = fi; si < N; si++) { //두번째 벌통 시작 위치
						for(int sj = 0; sj < N; sj++) {
							if(fi == si && fj + M > sj)
								continue;
							if(sj + M > N) 
								break;
							
							int price = calcMaxPrice(fi, fj);
							price += calcMaxPrice(si, sj);
							maxPrice = Math.max(maxPrice, price);
						}
					}
				}
			}
			
			sb.append("#").append(t).append(" ").append(maxPrice).append("\n");
		}
		System.out.print(sb);
	}

}
