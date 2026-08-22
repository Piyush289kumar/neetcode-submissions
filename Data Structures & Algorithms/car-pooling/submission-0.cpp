class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(10001, 0);

        for(int i=0; i<trips.size(); i++){
            // Starting = Passenger Count
            diff[trips[i][1]] += trips[i][0];

            // Ending = Passenger Count
            diff[trips[i][2]] -= trips[i][0];
        }

        int curr_cnt = 0;

        for(auto &it : diff){
            curr_cnt += it;
            
            if(curr_cnt > capacity) return false;
        }

        return true;
    }
};