import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int T, N;
	static int map[][] = new int[21][21];
	
	static void up() {
		for(int j = 0; j < N; j++) {
			int i = 0;
			while(i < N - 1) {
				if(map[i][j] == 0) {
					i++;
					continue;
				}
				int numIdx = i + 1;
				while(numIdx < N && map[numIdx][j] == 0) {
					numIdx++;
				}
				if(numIdx == N) {
					break;
				}
				if(map[i][j] != map[numIdx][j]) { //숫자 2개 찾아서 합치기
					i = numIdx;
					continue;
				}
				map[i][j] <<= 1;
				map[numIdx][j] = 0;
				i++;
			}
			int zeroIdx = 0;
			while(zeroIdx < N && map[zeroIdx][j] != 0) {
				zeroIdx++;
			}
			if(zeroIdx < N) {
				int numIdx = zeroIdx + 1;
				while(zeroIdx < N && numIdx < N) { //한쪽으로 쭉 밀기
					while(numIdx < N && map[numIdx][j] == 0) {
						numIdx++;
					}
					if(numIdx == N)
						break;
					int tmp = map[zeroIdx][j];
					map[zeroIdx][j] = map[numIdx][j];
					map[numIdx][j] = tmp;
					zeroIdx++;
					numIdx++;
				}
			}
		}
	}
	
	static void down() {
		for(int j = 0; j < N; j++) {
			int i = N - 1;
			while(i >= 0) {
				if(map[i][j] == 0) {
					i--;
					continue;
				}
				int numIdx = i - 1;
				while(numIdx >= 0 && map[numIdx][j] == 0) {
					numIdx--;
				}
				if(numIdx < 0) {
					break;
				}
				if(map[i][j] != map[numIdx][j]) { //숫자 2개 찾아서 합치기
					i = numIdx;
					continue;
				}
				map[i][j] <<= 1;
				map[numIdx][j] = 0;
				i--;
			}
			int zeroIdx = N - 1; //한쪽으로 쭉 밀기
			while(zeroIdx >= 0 && map[zeroIdx][j] != 0) {
				zeroIdx--;
			}
			if(zeroIdx >= 0) {
				int numIdx = zeroIdx - 1;
				while(zeroIdx >= 0 && numIdx >= 0) {
					while(numIdx >= 0 && map[numIdx][j] == 0) {
						numIdx--;
					}
					if(numIdx < 0)
						break;
					int tmp = map[zeroIdx][j];
					map[zeroIdx][j] = map[numIdx][j];
					map[numIdx][j] = tmp;
					zeroIdx--;
					numIdx--;
				}
			}
		}
	}
	
	static void left() { //up에서 i,j만 바꾸면 됨
		for(int j = 0; j < N; j++) {
			int i = 0;
			while(i < N - 1) {
				if(map[j][i] == 0) {
					i++;
					continue;
				}
				int numIdx = i + 1;
				while(numIdx < N && map[j][numIdx] == 0) {
					numIdx++;
				}
				if(numIdx == N) {
					break;
				}
				if(map[j][i] != map[j][numIdx]) { //숫자 2개 찾아서 합치기
					i = numIdx;
					continue;
				}
				map[j][i] <<= 1;
				map[j][numIdx] = 0;
				i++;
			}
			int zeroIdx = 0;
			while(zeroIdx < N && map[j][zeroIdx] != 0) {
				zeroIdx++;
			}
			if(zeroIdx < N) {
				int numIdx = zeroIdx + 1;
				while(zeroIdx < N && numIdx < N) { //한쪽으로 쭉 밀기
					while(numIdx < N && map[j][numIdx] == 0) {
						numIdx++;
					}
					if(numIdx == N)
						break;
					int tmp = map[j][zeroIdx];
					map[j][zeroIdx] = map[j][numIdx];
					map[j][numIdx] = tmp;
					zeroIdx++;
					numIdx++;
				}
			}
		}
	}
	
	static void right() { //down에서 i,j만 바꾸면 됨
		for(int j = 0; j < N; j++) {
			int i = N - 1;
			while(i >= 0) {
				if(map[j][i] == 0) {
					i--;
					continue;
				}
				int numIdx = i - 1;
				while(numIdx >= 0 && map[j][numIdx] == 0) {
					numIdx--;
				}
				if(numIdx < 0) {
					break;
				}
				if(map[j][i] != map[j][numIdx]) { //숫자 2개 찾아서 합치기
					i = numIdx;
					continue;
				}
				map[j][i] <<= 1;
				map[j][numIdx] = 0;
				i--;
			}
			int zeroIdx = N - 1; //한쪽으로 쭉 밀기
			while(zeroIdx >= 0 && map[j][zeroIdx] != 0) {
				zeroIdx--;
			}
			if(zeroIdx >= 0) {
				int numIdx = zeroIdx - 1;
				while(zeroIdx >= 0 && numIdx >= 0) {
					while(numIdx >= 0 && map[j][numIdx] == 0) {
						numIdx--;
					}
					if(numIdx < 0)
						break;
					int tmp = map[j][zeroIdx];
					map[j][zeroIdx] = map[j][numIdx];
					map[j][numIdx] = tmp;
					zeroIdx--;
					numIdx--;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception  {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++) {
        	st = new StringTokenizer(br.readLine());
        	N = Integer.parseInt(st.nextToken());
        	String inst = st.nextToken();
        	for(int i = 0; i < N; i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j = 0; j < N; j++) {
        			map[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	switch(inst) {
	        	case "up": 
	        		up();
	        		break;
	        	case "down": 
	        		down();
	        		break;
	        	case "left": 
	        		left();
	        		break;
	        	default:
	        		right();
	        		break;
        	}
        	sb.append("#" + t + "\n");
        	for(int i = 0; i < N; i++) {
        		for(int j = 0; j < N; j++) {
        			sb.append(map[i][j] + " ");
        		}
        		sb.append("\n");
        	}
        }
        System.out.println(sb);
	}
}
