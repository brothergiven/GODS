package Week1.brothergiven;

public class Solution {
    int[] g, s, w, t;
    int a, b;
    long answer;
    public long solution(int a, int b, int[] g, int[] s, int[] w, int[] t) {
        this.a = a;
        this.b = b;
        this.g = g;
        this.s = s;
        this.w = w;
        this.t = t;
    
        long lo = 1l; // 최소 시간
        long hi = (long) (2 * 2 * 1e14); // 걸리는 최대 시간
        answer = hi;
        binSearch(lo, hi);
        return answer;
    }

    void binSearch(long lo, long hi) {
        if (lo <= hi) {
            long mid = (lo + hi) / 2;
            int cities = g.length;
            long totalGold = 0;
            long totalSilver = 0;
            long totalWeight = 0;
            for (int i = 0; i < cities; i++) {
                int curCycleTime = 2 * t[i];
                long curMaxMove = mid / curCycleTime;
                long curRemainingTime = mid % curCycleTime;
                if (curRemainingTime >= curCycleTime / 2)
                    curMaxMove++;
                long curMaxWeight = curMaxMove * w[i];

                totalGold += Math.min(g[i], curMaxWeight);
                totalSilver += Math.min(s[i], curMaxWeight);
                totalWeight += Math.min(g[i] + s[i], curMaxWeight);
            }
            if (totalGold >= a && totalSilver >= b && totalWeight >= a + b) {
                answer = mid;
                binSearch(lo, mid - 1);
            } else
                binSearch(mid + 1, hi);
        } 
    }
}