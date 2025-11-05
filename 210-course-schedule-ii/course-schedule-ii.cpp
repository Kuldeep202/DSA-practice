class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto& p : prerequisites){
            int course = p[0], pre = p[1];
            indegree[course]++;
            graph[pre].push_back(course);
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            res.push_back(course);
            count++;

            for(int nbr : graph[course]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return count == numCourses ? res : vector<int>{};
    }
};