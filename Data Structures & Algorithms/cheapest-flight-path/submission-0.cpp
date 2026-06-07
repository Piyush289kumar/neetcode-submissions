class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : flights){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        // stops, node, price/wt
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});

        while(!q.empty()){
            auto [stops, node, wt] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){

                int adjNode = it.first;
                int adjWt = it.second;

                if(adjWt + wt < distance[adjNode] && stops <= k){
                    distance[adjNode] = adjWt + wt;
                    q.push({stops + 1, adjNode, adjWt + wt});
                }
            }
        }

        if(distance[dst] == 1e9) return -1;

        return distance[dst];
    }
};
