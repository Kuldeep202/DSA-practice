class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     map<int,int> mpp;

     for(auto num:nums){
        mpp[num]++;
     }
     int maxf=0;
     for(auto p:mpp){
        maxf=max(maxf,p.second);
     }
     int ans=0;
     for(auto q: mpp){
        if(q.second==maxf){
            ans+=q.second;
        }
     }
     return ans;
    }
};
