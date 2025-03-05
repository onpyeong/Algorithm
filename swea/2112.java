import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, D, W, K;
	static boolean film[][] = new boolean[14][21];
	static boolean temp[][] = new boolean[14][21];
	static int pick[] = new int[14];
	static int minCnt;
	
	static void calcInjectCombi(int k, int cnt) {
		if(cnt > minCnt) {
			return;
		}
		if(k == D) {
			if(check()) { //성능 검사
				minCnt = Math.min(minCnt, cnt);
			}
			return;
		}
		calcInjectCombi(k + 1, cnt);
		inject(k, true);
		calcInjectCombi(k + 1, cnt + 1);
		inject(k, false);
		calcInjectCombi(k + 1, cnt + 1);
		recover(k);
	}
	
	static void inject(int row, boolean state) {
		for(int j = 0; j < W; j++) {
			temp[row][j] = state;
		}
	}
	
	static void recover(int row) {
		for(int j = 0; j < W; j++) {
			temp[row][j] = film[row][j];
		}
	}
	
	static boolean check() { //성능 검사
		int cnt;
		boolean cur, isPass;
		for(int j = 0; j < W; j++) { //열에 대해서
			isPass = false;
			int i = 0;
			while(i < D) {
				cur = temp[i][j];
				cnt = 1;
				while(i + 1 < D && cur == temp[i + 1][j]) {
					cnt++;
					i++;
				}
				if(cnt >= K) {
					isPass = true;
				}
				i++;
			}
			if(!isPass) {
				return false;
			}
    	}
		return true;
	}
	
	static void copyTemp() {
		for(int i = 0; i < D; i++) {
    		for(int j = 0; j < W; j++) {
    			temp[i][j] = film[i][j];
    		}
    	}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	D = Integer.parseInt(st.nextToken());
        	W = Integer.parseInt(st.nextToken());
        	K = Integer.parseInt(st.nextToken());
        	for(int i = 0; i < D; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < W; j++) {
        			film[i][j] = st.nextToken().equals("1") ? true : false;
        		}
        	}
        	
        	copyTemp();
        	minCnt = 100;
        	calcInjectCombi(0, 0);
        	
        	sb.append("#" + t + " " + minCnt + "\n");
        }
        System.out.println(sb);

	}

}
