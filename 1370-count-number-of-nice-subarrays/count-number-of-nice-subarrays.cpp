class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int prefix=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
         
            prefix+=nums[i]%2;
           if(mpp.find(prefix-k)!=mpp.end()){
                count+=mpp[prefix-k];
            }
            mpp[prefix]++;
        }
        return count;
    }
};