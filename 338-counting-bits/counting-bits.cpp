class Solution {
public:
    int bitCount(int x) {
        if (x == 0) return 0;
        if ((x & 1) == 0) {
            return bitCount(x / 2);
        } else {
            return 1 + bitCount(x - 1);
        }
    }

    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        for (int i = 0; i <= n; i++) {
            result[i] = bitCount(i);
        }
        return result;
    }
};