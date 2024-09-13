class Solution {
    public long solution(int a, int b, int[] g, int[] s, int[] w, int[] t) {
        long answer = -1;
        long start = 1;
        long end = (long)(10e9 * 2 * 10e5* 2);
        int len = s.length;
        
        while(start <= end){
            int gold = 0, silver = 0, total = 0;
            long mid = (start + end) / 2;
            
            for(int i = 0; i < len; i++){
                int weight = w[i];
                int time = t[i];
                
                long cnt = mid / (2*time);
                if((mid % (2*time)) >= time) cnt++;
                
                gold += Math.min(g[i], weight*cnt);
                silver += Math.min(s[i], weight*cnt);
                total += Math.min(g[i] + s[i], weight*cnt);
            }
            if(gold >= a && silver >= b && total >= a+b){
                answer = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return answer;
    }
}