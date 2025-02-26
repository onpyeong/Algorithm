import java.util.*;
import java.io.*;

public class Solution {
	static int T, N, intervalCnt;
    static int h[] = new int[50005];
    static boolean visit[];
    
    static void init() {
    	intervalCnt = 0;
    	visit = new boolean[N];
    }
    
    static class Height implements Comparable<Height> {
    	int height;
    	int idx;
    	
    	public Height(int height, int idx) {
    		this.height = height;
    		this.idx = idx;
    	}

		@Override
		public int compareTo(Height o) {
			return o.height - this.height;
		}
    }
    
    static void findInterval() {
    	PriorityQueue<Height> pq = new PriorityQueue<>(); //최소힙 기본
    	for(int i = 0; i < N; i++) {
    		pq.offer(new Height(h[i], i));
    	}
    	
    	int idx, lIdx, rIdx;
    	int lc, rc;
    	while(!pq.isEmpty()) {
    		idx = pq.poll().idx;
    		if(!visit[idx]) {
    			//구간 계산하기
    			visit[idx] = true;
    			lc = rc = 0;
    			lIdx = rIdx = idx;
    			//왼쪽 체크
    			while(lIdx > 0 && h[lIdx - 1] < h[lIdx]) {
    				lIdx--;
    				lc++;
    			}
    			//오른쪽 체크
    			while(rIdx < N - 1 && h[rIdx] > h[rIdx + 1]) {
    				rIdx++;
    				rc++;
    			}
    			intervalCnt += lc * rc;
    			//방문 처리
    			if(idx - 1 >= 0)
    				visit[idx - 1] = true;
    			if(idx + 1 < N)
    				visit[idx + 1] = true;
    		}
    	}
    }
    
	public static void main(String args[]) throws Exception {
        Scanner br = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        T = br.nextInt();
        for(int t = 1; t <= T; t++) {
            N = br.nextInt();
            init();
            for(int i = 0; i < N; i++) {
            	h[i] = br.nextInt();
            }
            
            findInterval();
            
        	sb.append("#" + t + " " + intervalCnt + "\n");
        }
        System.out.print(sb);
    }
}
