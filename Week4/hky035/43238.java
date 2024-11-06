package week4;

import java.util.Arrays;

public class ans43238 {
	
	public long solution(int n, int[] times) {
		Arrays.sort(times); // 가장 오래 걸리는 심사 시간을 알기 위해 정렬
		
		long answer = 0;
		long left   = 0;
		long right  = times[times.length-1] * (long)n; // worst
		
		while(left <= right) {
			long mid 	= (left + right) / 2;
			long count	= 0; // 심사 가능한 인원 수
			
			for(int time : times)
				count += (mid / time); 
			
			if(count >= n) {	// 심사 가능
				right  = mid - 1;
				answer = mid;   // right 감소 후 심사 불가능할 경우 대비 값 저장  					
			} else {
				left   = mid + 1;
			}
		}
		
		return answer;
	}
}
