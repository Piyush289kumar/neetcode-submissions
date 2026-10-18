class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;

        unordered_map<char,int> hash;

        int n = s.size();

        int l=0, r=0;

        for(int r=0; r<n; r++){           

            hash[s[r]]++;

            // remove repeating chars
            while(hash[s[r]] > 1){
                hash[s[l]]--;
                l++;
            }

            int curr_len = (r-l+1);
            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};
