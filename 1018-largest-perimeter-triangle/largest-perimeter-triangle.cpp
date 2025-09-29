class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-2; i++){
            int sum=arr[i]+arr[i+1];
            if(sum>arr[i+2]){
                
                ans=max(ans,arr[i]+arr[i+1]+arr[i+2]);
            }
        }
        return ans;
    }
};