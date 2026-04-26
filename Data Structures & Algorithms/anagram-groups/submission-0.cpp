class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp;

        for(auto it : strs){

            string tmp = it;
            sort(it.begin(), it.end());
            mp[it].push_back(tmp);
        }


        vector<vector<string>> ans;

        for(auto key : mp){
            ans.push_back(key.second);
        }

        return ans;
    }
};
