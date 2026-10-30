class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        map<int,int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto idx : freq){
            
            if(idx.second >= 2){
                return true;
            }

        }

        return false;
    }
};
