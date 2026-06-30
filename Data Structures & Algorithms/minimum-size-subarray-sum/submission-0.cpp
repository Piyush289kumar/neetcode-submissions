class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        long long sum = 0;

        int l=0;
        for(int r=0; r<nums.size(); r++){
            sum += nums[r];

            while(target <= sum){
                minlen = min(minlen, (r-l+1));
                sum -= nums[l];
                l++;
            }

        }

        return (minlen == INT_MAX ? 0 : minlen);
    }
};