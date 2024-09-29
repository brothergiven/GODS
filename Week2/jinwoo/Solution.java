class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int[][] road = new int[n+1][m+1];
        for(int i = 0; i < puddles.length; i++)
            road[puddles[i][1]][puddles[i][0]] = -1;
        
        road[1][1] = 1;
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(road[i][j] == -1) 
                    continue;
                if(road[i-1][j] > 0)
                    road[i][j] += road[i-1][j] % 1000000007;
                if(road[i][j-1] > 0)
                    road[i][j] += road[i][j-1] % 1000000007;
            }
        }
        answer = road[n][m] % 1000000007;
        return answer;
    }
}
