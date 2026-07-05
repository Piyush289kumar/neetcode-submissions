class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0];
        int vote = 0;
        unordered_map<int,int> hash;

        for(auto &n : nums){
            if(vote == 0) candidate = n;
            if(candidate == n) vote++;
            else vote--;
            hash[n]++;
        }


        return ((nums.size()/2) <= hash[candidate] ? candidate : -1);
        
    }
};