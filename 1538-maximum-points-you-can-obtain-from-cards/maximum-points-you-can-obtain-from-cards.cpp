class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int rm=0;
        int lm=0;
        int n=nums.size();
        int maxi=0;
       for(int i=0; i<k; i++){
           lm+=nums[i];
       }
       maxi=lm;
       for(int i=0; i<k; i++){
         lm-=nums[k-1-i];
         rm+=nums[n-1-i];
         maxi=max(rm+lm,maxi);
       }
       return maxi;
    }
};