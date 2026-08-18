class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> set(nums.begin(), nums.end());

        int mxLen = 0;

        for(auto &n : set){

            // starting point find
            if(!set.count(n-1)){
                int currLen = 0, num = n;
                
                while(set.count(num)){
                    currLen++;
                    num++;
                }

                mxLen = max(mxLen, currLen);
            }
        }

        return mxLen;
    }
};
