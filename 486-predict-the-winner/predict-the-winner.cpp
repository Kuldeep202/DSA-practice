class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));
        vector<long long>prefix(n+1,0);
        prefix[1] = nums[0];
        for(int i=2;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] =  max(nums[i] + ( prefix[j+1]-prefix[i+1]- dp[i + 1][j]),
                           nums[j] + ( prefix[j]-prefix[i] - dp[i][j - 1]));
            }
        }
        long long p1 = dp[0][n-1];
        long long p2 = prefix[n] - p1;
        return p1>=p2;
    }
};