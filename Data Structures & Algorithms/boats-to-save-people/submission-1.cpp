class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l=0, h=n-1, boats = 0;

        while(l <= h){
            int remaining_limit = limit - people[h];

            if(remaining_limit >= people[l] && l < h){
                remaining_limit -= people[l];
                l++;
            }

            boats++;
            h--;
        }

        return boats;
    }
};