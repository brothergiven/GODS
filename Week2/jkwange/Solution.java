import java.util.Arrays;

class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] route = new int[n][m];

        for (int[] puddle : puddles) {
            route[puddle[1] - 1][puddle[0] - 1] = -1;
        }

        route[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (route[i][j] == -1) continue;

                if (i > 0 && route[i - 1][j] != -1)
                    route[i][j] += route[i - 1][j];

                if (j > 0 && route[i][j - 1] != -1)
                    route[i][j] += route[i][j - 1];

                route[i][j] %= 1000000007;
            }
        }

        return route[n - 1][m - 1];
    }


}