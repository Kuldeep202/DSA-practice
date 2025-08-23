class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]=1;
        int count=0;
        int prefixs=0;
        for(int i=0 ; i<nums.size(); i++){
            prefixs+=nums[i];
            if(freq.find(prefixs-k)!=freq.end()){
                count+=freq[prefixs-k];
            }
            freq[prefixs]++;
        }
        return count;
    }
};