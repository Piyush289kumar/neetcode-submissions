class Solution {
public:

    string encode(vector<string>& strs) {
        string ecn;
        for(auto& str : strs){
            ecn += to_string(str.size()) + "#" + str;
        }
        return ecn;
    }

    vector<string> decode(string s) {
        vector<string> dec;
        int i = 0;
        
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i));

            dec.push_back(s.substr(j+1, len));

            i = j + len + 1;

        }
        return dec;
    }
};
