class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> hash(256, 0);
        for(auto &it : t){
            hash[it]++;
        }

        int s_idx = -1, minLen = INT_MAX, l = 0, cnt = 0;

        for(int r=0; r<s.size(); r++){

            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            // valid window
            while(cnt == t.size()){

                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    s_idx = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }

        }

        return (s_idx == -1 ? "" : s.substr(s_idx, minLen));
    }
};
