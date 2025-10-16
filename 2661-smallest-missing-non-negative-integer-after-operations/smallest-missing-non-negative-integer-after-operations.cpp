class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans=0;
        map<int,int> mpp;
        for(auto it : nums){
            int x=((it%value)+value)%value;
            mpp[x]++;
        }

        while(1){
            int r=ans%value;
            if(mpp[r]>0){
                ans++;
                mpp[r]--;
            }
            else{
                return ans;
            }
        }
        return 0;
    }
};