class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;

        int left = 0, right = 0, n = nums.size();
        
        while(right < n){

            if(nums[right] != 1){
                left = right + 1;
            }

            maxOnes = max(maxOnes, (right - left + 1));

            right++;
        }

        return maxOnes;
    }
};