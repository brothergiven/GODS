class Solution {
    final int mod = 1000000007;
    int [][] map;
    public int solution(int m, int n, int[][] puddles) {
        map = new int[n+1][m+1];
        for(int i = 0;i<puddles.length;i++) {
            map[puddles[i][1]][puddles[i][0]] = -1;
        }

        for(int i = 1; i <= n; i++) {
            if(map[i][1] == -1) {
                for(int j = i;j<=n;j++){
                    map[j][1] = 0;
                }
                break;
            }
            map[i][1] = 1;
        }

        for(int i = 1; i <= m; i++) {
            if(map[1][i] == -1) {
                for(int j = i;j<=m;j++){
                    map[1][j] = 0;
                }
                break;
            }
            map[1][i] = 1;
        }

        for(int i = 2; i<=n; i++) {
            for(int j =2; j<=m; j++) {
                if(map[i][j]==-1){
                    map[i][j] = 0;
                    continue;
                }
                map[i][j] = (map[i-1][j] + map[i][j-1])%mod;

            }
        }
        return map[n][m];
    }
}