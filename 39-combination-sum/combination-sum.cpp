class Solution {
public:
void BT(vector<vector<int>>&ans,int index,vector<int> current,vector<int>& candidates, int target){
    if(target==0){
        ans.push_back(current);
        return;
    }
    if(target<0||index==candidates.size()) return;
    current.push_back(candidates[index]);
    BT(ans,index,current,candidates,target-candidates[index]);
    current.pop_back();
    BT(ans,index+1,current,candidates,target);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> current;
        BT(ans,0,current,candidates, target);
        return ans;
    }
};