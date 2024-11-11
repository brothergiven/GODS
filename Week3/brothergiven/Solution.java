class Solution {

    // Floyd



    public int solution(int n, int s, int a, int b, int [][] fares){

        int dist[][] = new int[n+1][n+1];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                if(i != j)
                    dist[i][j] = 20000000;
        }
        for(int[] arr : fares){
            dist[arr[0]][arr[1]] = arr[2];
            dist[arr[1]][arr[0]] = arr[2];
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int answer = dist[s][a] + dist[s][b];
        for(int i = 1; i <= n; i++){
            // s -> i -> a
            answer = Math.min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }

        return answer;
    }





}