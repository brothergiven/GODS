import java.util.*;
class Solution {
    int n;
    int[] times;
    boolean isAvailable(long time){
        long client = 0;
        for(int i = 0;i<times.length;i++){
            client +=time/times[i];
        }
        if(client>=n)
            return true;
        return false;
    }
    public long solution(int n, int[] times) {
        long answer = 0;
        this.n = n;
        Arrays.sort(times);
        this.times = times;
        long end =(long)n*times[times.length-1];
        long start = times[0];
        while(start<=end){
            long mid = (start+end)/2;
            if(isAvailable(mid)){
                answer = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return answer;
    }
}