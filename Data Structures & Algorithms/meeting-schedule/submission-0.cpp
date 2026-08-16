/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& arr) {
        
         // Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            
            if(ans.empty() || ans.back()[1] <= arr[i].start){
                ans.push_back({arr[i].start, arr[i].end});
            }else{
                return false;
            }
        }
        
        return true;
    }
};
