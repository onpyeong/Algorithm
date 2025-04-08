import java.io.*;
import java.util.*;

public class Solution {
	
	static int T;
	static int N;
	static int a[] = new int[1000];
	static List<Integer> lis;
	
	static int lowerBound(int x) {
		int s = -1, e = lis.size();
		int mid;
		while(s + 1 < e) {
			mid = (s + e) / 2;
			if(x > lis.get(mid)) {
				s = mid;
			}else {
				e = mid;
			}
		}
		return e;
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int idx;
        
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            lis = new ArrayList<>();
            
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());  
            for (int i = 0; i < N; i++) {
            	a[i] = Integer.parseInt(st.nextToken());
            }
            
            lis.add(a[0]);
            for (int i = 1; i < N; i++) {
            	if(a[i] > lis.get(lis.size() - 1)) {
            		lis.add(a[i]);
            	}else {
            		idx = lowerBound(a[i]);
            		lis.set(idx, a[i]);
            	}
            }

            sb.append("#").append(t).append(" ").append(lis.size()).append("\n");
        }
        System.out.print(sb);
    }
}
