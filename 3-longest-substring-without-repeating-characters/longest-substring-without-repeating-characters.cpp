class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int left=0;
        vector<int> mpp(256,-1);

        int right=0;
        while(right<s.size()){
            if(mpp[s[right]]!=-1){
                left=max(left,mpp[s[right]]+1);
            }
            maxi=max(maxi,right-left+1);
            mpp[s[right]]=right;
            right++;
        }
        return maxi;
    }
};