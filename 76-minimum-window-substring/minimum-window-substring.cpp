class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.size(), m = t.size();
         map<int,int> mpp;
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
            while(mpp[s[j]]<0){
                mpp[s[j]]++;
                j++;
            }
            
            if(i-j+1<minlen&& count==m){
                minlen=i-j+1;
                sindex=j;
            }
        }
        if(sindex==-1) return "";
        return s.substr(sindex,minlen);
}
    
};