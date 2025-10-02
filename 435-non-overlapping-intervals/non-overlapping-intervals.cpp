class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){
            return b[1]>a[1];
        });
        int lastend=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<lastend){
                count++;
            }
            else{
                lastend=intervals[i][1];
            }
        }
       return count;
    }
};