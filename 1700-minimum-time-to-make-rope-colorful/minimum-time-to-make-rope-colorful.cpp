class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int result=0;
        int i=0;
        int j=1;
        queue<int>q;
        while(i<n-1&&j<n)
        {
            while(!q.empty())
            {
                if(i==q.front())
                {
                    q.pop();
                    i++;
                }
                else break;
            }
            if(colors[i]==colors[j])
            {
                if(neededTime[i]>=neededTime[j])
                {
                    result+=neededTime[j];
                    q.push(j);
                    j++;
                }
                else
                {
                    result+=neededTime[i];
                    i++,j++;
                }
            }
            else i++,j++;
        }
        return result;
    }
};