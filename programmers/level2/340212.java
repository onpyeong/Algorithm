class Solution {
    
    static int c_diffs[];
    static int c_times[];
    static long c_limit;
    static int puzzle_size;
    
    private long calcTotalTime(long level) {
        long total_time = 0;
        if(c_diffs[0] <= level) {
            total_time += c_times[0];
        }else {
            total_time += c_times[0] * (c_diffs[0] - level) + c_times[0];
        }
        
        for(int i = 1; i < puzzle_size; i++) {
            if(c_diffs[i] <= level) {
                total_time += c_times[i];
            }else {
                total_time += (c_times[i] + c_times[i - 1]) * (c_diffs[i] - level) + c_times[i];
            }
        }
        return total_time;
    }
    
    
    
    private long binarySearch() {
        long s = 0L, e = 100005; // diff의 최댓값이 max 값 // Long.MAX_VALUE;
        long mid;
        while(s + 1 < e) {
            mid = (s + e) / 2; // 숙련도
            if(calcTotalTime(mid) > c_limit) {
                s = mid;
            }else {
                e = mid;
            }
        }
        return e;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        
        c_diffs = diffs;
        c_times = times;
        c_limit = limit;
        puzzle_size = diffs.length;
        
        answer = (int) binarySearch();
        
        return answer;
    }
}
