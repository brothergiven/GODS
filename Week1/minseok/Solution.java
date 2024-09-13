class Solution {
    final long maxWeight = 2*(long)Math.pow(10,9); //금과 은의 최대 무게
    final long maxCyCleTime = 2*(long)Math.pow(10,5);//왕복으로 걸리는 최대 이동 시간
    public boolean checkAvailableMoving(int a, int b, int []g, int[]s, int []w, int[]t, long time){
        int totalCity = g.length;
        long totalGold = 0;//운반한 금 양
        long totalSilver = 0;//운반한 은 양
        long totalWeight = 0;//운반한 전체 자원 양
        for(int i = 0 ;i<totalCity;i++){
            int curGold = g[i];
            int curSilver = s[i];
            int curWeight = w[i];
            int curCycleTime = 2*t[i];
            long curMaxMove = time/curCycleTime;//왕복으로 이동할 수 있는 횟수
            long curRemainingTime = time%curCycleTime;//자투리 시간
            if(curRemainingTime >=curCycleTime/2)
                curMaxMove++;//자투리 시간이 편도로 이동할 수 있는 시간보다 길면 편도로 한 번 더 운송할 수 있음
            long curMaxWeight = curMaxMove * curWeight;//운반할 수 있는 최대 양

            totalGold +=Math.min(curGold,curMaxWeight);//현재 도시에서 운반할 수 있는 금의 양
            totalSilver +=Math.min(curSilver,curMaxWeight);//현재 도시에서 운반할 수 있는 은의 양
            totalWeight +=Math.min(curGold+curSilver,curMaxWeight);//현재 도시에서 운반할 수 있는 전체 자원의 양
        }
        return totalGold >= a && totalSilver >= b && totalWeight >= a + b;//모든 도시를 다 확인한 다음에 조건을 충족하는지 확인

    }
    public long solution(int a, int b, int[] g, int[] s, int[] w, int[] t) {
        long start = 1;
        long end = 2* maxCyCleTime * maxWeight;//걸릴 수 있는 최악의 시간
        long answer = end;
        while(start<=end){//이분 탐색으로 반복문 돎
            long mid = start+(end-start)/2;
            if(checkAvailableMoving(a,b,g,s,w,t,mid)){//조건에 충족하면 정답 수정후 상한선 줄임
                answer = mid;
                end=mid-1;
                continue;
            }
            start = mid+1;//조건 충족 안하면 하한선을 올림
        }
        return answer;
    }
}