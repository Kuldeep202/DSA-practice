class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int left=0;
        int count=0;
        for(int right=0; right<fruits.size(); right++){
           mpp[fruits[right]]++;
           while(mpp.size()>2){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0){
                mpp.erase(fruits[left]);
            }
            left++;
           }
           count=max(count,right-left+1);
        }
        return count;
    }
};