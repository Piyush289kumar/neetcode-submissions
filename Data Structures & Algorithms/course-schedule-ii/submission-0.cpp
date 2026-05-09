class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto &pre : prerequisites){
            int u = pre[0];
            int v = pre[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // push all 0 degree node
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        int cnt = 0;

        // topo sort
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            cnt++;
            q.pop();

            for(auto num : adj[node]){
                indegree[num]--;
                
                if(indegree[num] == 0) q.push(num);
            }
        }

        // topo sort fail
        if(cnt != numCourses) return {};

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
