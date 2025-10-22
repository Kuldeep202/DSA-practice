class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations)    
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int ans=0, cnt=0;
        int l=0, r=0;

        for (int i=0; i<n; i++) {

        if(i-1>=0&&nums[i]==nums[i-1])continue;

         int x=nums[i];
         int L=max(1,x-k);
         int R=min(nums.back(), x+k);

            int f=0;
            for (int j=i;j<n && nums[j]==x; j++) f++;

            while (l<=i && nums[l]<L) l++;


            while (r+1<n && nums[r+1]<=R) r++;

            cnt=r-l+1;
            ans=max(ans, f+min(cnt-f, numOperations));
        }
        l=0;
        for (r=0; r<n; r++) {
            int x=nums[r];
            int L=max(1, x-2*k);
            while (l<r && nums[l]<L) l++;
            ans=max(ans, min(r-l+1, numOperations));
        }
        return ans;
    }
};