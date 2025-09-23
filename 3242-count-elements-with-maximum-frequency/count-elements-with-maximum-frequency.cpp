class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     map<int,int> mpp;

     int maxf=0;
     for(auto num:nums){
        mpp[num]++;
         maxf=max(maxf,mpp[num]);
     }
    //  for(auto p:mpp){
       
    //  }
     int ans=0;
     for(auto q: mpp){
        if(q.second==maxf){
            ans+=q.second;
        }
     }
     return ans;
    }
};
