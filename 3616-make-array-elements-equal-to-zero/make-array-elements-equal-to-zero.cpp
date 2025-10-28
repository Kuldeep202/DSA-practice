class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int n = nums.size();

        int res  = 0;
        int curr = 0;

        int totalSum = accumulate(begin(nums), end(nums), 0);

        for(int i = 0; i < n; i++){

            curr += nums[i];    

            int leftSum  = curr;
            int rightSum = totalSum - leftSum;

            if(nums[i] != 0)
                continue;

            if(leftSum == rightSum)
                res += 2;

            else if(abs(leftSum - rightSum) == 1)
                res += 1;
        }

        return res;

    }
};