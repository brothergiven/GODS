class Solution {
    final int max_value = 1000000;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int graph[][] = new int[n+1][n+1];
        for (int i = 0 ;i<=n;i++){
            for(int j = 0 ;j<=n;j++){
                if(i==j)
                    continue;
                graph[i][j] = max_value;
            }
        }

        for(int i = 0 ;i<fares.length;i++){
            graph[fares[i][0]][fares[i][1]] = fares[i][2];
            graph[fares[i][1]][fares[i][0]] = fares[i][2];
        }

        for(int k = 1; k<=n;k++){
            for(int i = 1; i<=n;i++){
                for(int j = 1; j<=n; j++){
                    if(graph[i][j] > graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }

        int answer = graph[s][1] + graph[1][a] + graph[1][b];
        for(int i = 2; i<=n;i++){
            if(answer> graph[s][i] + graph[i][a] + graph[i][b])
                answer = graph[s][i] + graph[i][a] + graph[i][b];
        }
        return answer;
    }
}