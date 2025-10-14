class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        for (int a = 0; a + 2 * k <= n; a++) {
            bool first = (inc[a + k - 1] >= k);
            bool second = (inc[a + 2 * k - 1] - inc[a + k - 1] >= k) ||
                          (inc[a + 2 * k - 1] >= k && inc[a + k] >= k);
            bool ok1 = true, ok2 = true;
            for (int i = a + 1; i < a + k; i++)
                if (nums[i] <= nums[i - 1]) ok1 = false;
            for (int i = a + k + 1; i < a + 2 * k; i++)
                if (nums[i] <= nums[i - 1]) ok2 = false;
            
            if (ok1 && ok2) return true;
        }
        return false;
    }
};
