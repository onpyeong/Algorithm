import java.io.*;
import java.util.*;

public class Solution {
	static int T, lose, win;
	static int kyu[] = new int[13];
	static boolean kyuUsed[] = new boolean[20];
 	static int inNumType[] = new int[13];
	static int in[] = new int[13];
	static boolean isUsed[] = new boolean[13];
	
	static void init() {
		win = 0;
		lose = 0;
		for(int i = 1; i <= 18; i++) {
			kyuUsed[i] = false;
		}
	}
	
	static void playGame(int k, int kyuScore, int inScore) {
		if(k == 9) {
			if(kyuScore > inScore)
				win++;
			else if(kyuScore < inScore)
				lose++;
			return;
		}
		int kScore, iScore;
		for(int i = 0; i < 9; i++) {
			if(isUsed[i])
				continue;
			kScore = 0;
			iScore = 0;
			in[k] = inNumType[i];
			isUsed[i] = true;
			if(kyu[k] < in[k])
				iScore += kyu[k] + in[k];
			else
				kScore += kyu[k] + in[k];
			playGame(k + 1, kyuScore + kScore, inScore + iScore);
			isUsed[i] = false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());
			init();
			for(int i = 0; i < 9; i++) {
				kyu[i] = Integer.parseInt(st.nextToken());
				kyuUsed[kyu[i]] = true;
			}
			int idx = 0;
			for(int i = 1; i <= 18; i++) {
				if(!kyuUsed[i])
					inNumType[idx++] = i;
			}
			playGame(0, 0, 0);
			
			sb.append("#" + t + " " + win + " " + lose + "\n");
		}
		System.out.println(sb);
	}

}
