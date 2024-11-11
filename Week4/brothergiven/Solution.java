package Week4.brothergiven;

public class Solution {
    int[] times;
    public long solution(int n, int[] times) {
        // 이진탐색 수행. 탐색범위 : 극단적인 최소 ~ 극단적인 최대.
        // 극단적인 최소 : 0
        long left = 0;
        // 극단적인 최대 : n명 전부가 min(times)에서 검사를 받음 : min * n
        long right = Long.MAX_VALUE;
        for(int time : times) right = Math.min(right, time);
        right *= n;
        long answer = 0;
        this.times = times;

        /**
         * 이진 탐색 수행
         * 종료 조건 : mid 값이 모든 사람이 심사를 받는데 걸리는 최소 시간
         */
        long mid;
        while (left <= right){
            // 1. 이분탐색은 while(true) 로 끝내는게 아니라 left <= right로 하는게 정배
            // while(true) : ㅅㅂ 못찾으면 어쩔라고
            mid = (left + right) / 2;
            // mid 값을 어떻게 검사?
            // times[]의 모든 원소에 대해 mid / time 한 값을 전부 더해서
            // n값을 채워보고 n값이 넘친다면 top = mid, else bot = mid
            if(check(mid, n)){
                answer = mid;
                right = mid - 1;
            }
            else 
                left = mid + 1;
            
        }
        return answer;        
    }

    boolean check(long mid, int n){
        long temp = 0; // temp 값과 n 값 비교
        for(int time : times)
            temp += mid / time;
        // tmp > n : 넘쳤음
        // tmp == n : 딱맞음
        // tmp < n : 부족함
        return temp >= n; // temp > n : 넘쳤음
    }

}