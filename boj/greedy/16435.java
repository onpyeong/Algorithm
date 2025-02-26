import java.io.*;
import java.util.*;

public class Main {
	
	static int N, L;
	static int h[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		h = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			h[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(h);
		
		for(int i = 0; i < N; i++) {
			if(L >= h[i]) {
				L++;
			}else {
				break;
			}
		}
		System.out.println(L);
	}

}
