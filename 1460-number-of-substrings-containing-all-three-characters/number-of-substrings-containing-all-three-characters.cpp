class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int n=s.size();
        int count=0;
        map<char,int> mpp;
        for(int right=0; right<s.size(); right++){
            mpp[s[right]]++;
            while(mpp.size()==3){
                count+=(n-right);
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
          
            }
        }
        return count;
    }
};