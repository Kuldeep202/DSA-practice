class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int right=0; 
        int zerocount=0;
        int left=0;
        while(right<nums.size()){
            if(nums[right]==0) zerocount++;
            while(zerocount>k){
                if(nums[left]==0) zerocount--;
                left++;
            }
            maxi=max(maxi,right-left+1);
        right++;
        }
        return maxi;
    }
};