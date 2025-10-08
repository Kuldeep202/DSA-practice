class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;
        for (int spell : spells) {
            long long minPotion = ceil((double)success/spell);
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = n - (it - potions.begin());
            ans.push_back(count);
        }
        return ans;
    }
};