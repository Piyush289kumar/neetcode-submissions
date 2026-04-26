class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        for(int idx = 0; idx < t.size(); idx++){

            if(mp.find(t[idx]) != mp.end()){

                mp[t[idx]]--;

            }else{
                return false;
            }

        }

        for(auto ch : mp){
            if(ch.second != 0){
                return false;
            }
        }

        return true;
    }
};
