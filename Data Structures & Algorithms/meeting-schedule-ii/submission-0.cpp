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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<int> start, end;
        for(auto &it : intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0, maxi = 0;
        
        int i = 0, j = 0;
        
        while(i < start.size()){
            
            if(start[i] < end[j]){
                rooms++;
                maxi = max(maxi, rooms);
                i++;
            }else{
                rooms--;
                j++;
            }
        }
        
        return maxi;
    }
};
