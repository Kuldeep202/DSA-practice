class Solution {
public:
    int ladderLength(string st, string tar, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({st,1});
        unordered_set<string> s(word.begin() , word.end());
        s.erase(st);
        while(!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(str == tar) return steps;
            for(int i=0 ; i<str.length() ; i++){
                char org = str[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    str[i] = ch;
                    if(s.find(str) != s.end()){
                        s.erase(str);
                        q.push({str , steps+1});
                    }
                }
                str[i] = org;
            }
        }
        return 0;
    }
};