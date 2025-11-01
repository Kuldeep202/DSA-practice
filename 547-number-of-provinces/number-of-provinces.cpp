class Solution {
public:
    void BFS(vector<vector<int>> v, vector<bool> &vis, int start) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int curr = q.front();
                q.pop();

                if (!vis[curr]) {
                    for (int j = 0; j < v[curr].size(); j++) {
                        if (v[curr][j] == 1 && j != curr) q.push(j);
                    }

                    vis[curr] = true;
                } else continue;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int n = isConnected.size();
        vector<bool> vis(n, false);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                BFS(isConnected, vis, i);
                res++;
            }
            else continue;
        }

        return res;
    }
};