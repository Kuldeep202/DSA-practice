class Solution {
public:
    int dp[205][205];
    int r,c;
    int rec(int i, int j, vector<vector<int>>& grid)
    {
        if(i>=r || j>=c) return INT_MAX;
        if(i == r-1 && j == c-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int right = rec(i,j+1,grid);
        int down = rec(i+1,j,grid);
        return dp[i][j] = grid[i][j] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,grid);
    }
};