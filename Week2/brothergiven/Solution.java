package Week2.brothergiven;
public class Solution {
    static public final int MAX_VALUE = 1000000007;
	static public int solution(int m, int n, int[][] puddles) {
		// m : 가로, n : 세로
		boolean puddlesB[][] = new boolean[n + 1][m + 1];
		// puddles boolean setting
		for (int arr[] : puddles)
			puddlesB[arr[1]][arr[0]] = true;

		int dp[][] = new int[n + 1][m + 1];
		dp[1][1] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if(!puddlesB[i][j]){
					dp[i][j] = (dp[i-1][j] + dp[i][j]) % MAX_VALUE;
					dp[i][j] = (dp[i][j-1] + dp[i][j]) % MAX_VALUE;
				}
				// dp[i][j] = (dp[i][j] + (puddlesB[i - 1][j] ? 0 : dp[i - 1][j])) % MAX_VALUE;
				// dp[i][j] = (dp[i][j] + (puddlesB[i][j - 1] ? 0 : dp[i][j - 1])) % MAX_VALUE;
			}
		}

		return dp[n][m];
	}
    
    public static void main(String[] args) {
    	int puddles[][] = {{2, 2}};
    	System.out.println(solution(4, 3, puddles));
    }
}