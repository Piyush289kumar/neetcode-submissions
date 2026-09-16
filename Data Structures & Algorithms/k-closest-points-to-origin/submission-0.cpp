class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;

        for(int i = 0; i < points.size(); i++){

            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = 0;
            int y2 = 0;

            double ans = sqrt( ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));

            pq.push({ans, points[i]});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
