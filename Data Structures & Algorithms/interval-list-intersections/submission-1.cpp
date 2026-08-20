class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;

        vector<vector<int>> ans;

        while(i < n && j < m){

            // Take Intersection points
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // Intersection found
            if(start <= end){
                ans.push_back({start, end});
            }

            // Move Smaller Span
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }

        return ans;
    }
};