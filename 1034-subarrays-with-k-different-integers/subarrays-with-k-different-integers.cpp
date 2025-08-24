class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int left=0;
        map<int,int> mpp;
        int count=0;
        for(int right=0; right<nums.size(); right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;


        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};