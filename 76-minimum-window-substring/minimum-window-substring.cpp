class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.size(), m = t.size();
         vector<int> mpp(256,0);
         if(m>n) return "";
        for(int i=0; i<m; i++){
            mpp[t[i]]++;
        }
        int j=0; int minlen=INT_MAX;
        int count=0; 
        int sindex=-1;
        for(int i=0; i<s.size(); i++){
            if(mpp[s[i]]>0){
                count++;
            }
                mpp[s[i]]--;
           while(count==m){
            if(minlen>i-j+1){
                minlen=i-j+1;
                sindex=j;
            }
            mpp[s[j]]++;
            if(mpp[s[j]]>0) count--;
            j++;
           }
        }
        if(sindex==-1) return "";
        return s.substr(sindex,minlen);
}
    
};