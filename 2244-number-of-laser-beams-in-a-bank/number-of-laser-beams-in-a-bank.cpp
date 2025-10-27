class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevDeviceCount = 0;
        
        for (const string& row : bank) {
            int currentDeviceCount = 0;
            for (char cell : row) {
                currentDeviceCount += cell & 1;
            }
            if (currentDeviceCount > 0) {
                totalBeams += prevDeviceCount * currentDeviceCount;
                prevDeviceCount = currentDeviceCount;
            }
        }
        
        return totalBeams;
    }
};