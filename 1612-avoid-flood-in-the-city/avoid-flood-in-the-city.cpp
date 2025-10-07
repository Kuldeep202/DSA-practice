class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(),1);
        map<int,int> mpp;
        set<int> s;
        for(int i=0; i<rains.size(); i++){
            if(rains[i]==0){
                s.insert(i);
            }
            else{
                if(mpp.find(rains[i])!=mpp.end()){
                    auto it=s.upper_bound(mpp[rains[i]]);
                    if(it==s.end()){
                        return {};
                    }
                    ans[*it]=rains[i];
                    s.erase(it);
                }
                mpp[rains[i]]=i;
                ans[i]=-1;
                
            }
        }
        return ans;
    }
};