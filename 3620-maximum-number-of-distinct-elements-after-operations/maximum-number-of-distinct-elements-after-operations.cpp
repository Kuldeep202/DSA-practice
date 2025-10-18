class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN; 
        int count = 0;

        for (int x : nums) {
            long long left = x - k;
            long long right = x + k;
            long long pick = max(left, last + 1);

            if (pick <= right) {
                count++;
                last = pick;
            }
        }

        return count;
    }
};
