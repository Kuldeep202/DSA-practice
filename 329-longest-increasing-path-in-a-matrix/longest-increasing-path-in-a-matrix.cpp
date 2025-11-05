class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int left = 0;
        if((j-1>=0) && matrix[i][j] < matrix[i][j-1]) {
            left =  f(i, j-1, matrix, dp);
        }

        int right = 0;
        if((j+1<n) && matrix[i][j] < matrix[i][j+1]) {
            right =  f(i, j+1, matrix, dp);
        }
        int down = 0;
        if((i+1<m) && matrix[i][j] < matrix[i+1][j]) {
            down = f(i+1, j, matrix, dp);
        }
        int up=0;
        if((i-1>=0) && matrix[i][j] < matrix[i-1][j]) {
            up = f(i-1, j, matrix, dp);
        }

        return dp[i][j] = 1+max(max(left, right), max(down, up));
        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                maxLen = max(maxLen, f(i, j, matrix, dp));
            }
        }
        return maxLen;
    }
};