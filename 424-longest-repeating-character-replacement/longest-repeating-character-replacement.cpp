class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        map<int,int> mpp;
        int maxlen=0;
        int maxf=0;
        for(int right=0; right<s.size(); right++){
            mpp[s[right]]++;
            maxf=max(maxf,mpp[s[right]]);
            if(abs(right-left+1-(maxf))<=k){
                maxlen=max(maxlen,right-left+1);
            }
            else{
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
        }
        return maxlen;
    }
};