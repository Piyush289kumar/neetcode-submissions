class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<pair<int, int>> sortVec(freq.begin(), freq.end());

        sort(sortVec.begin(), sortVec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        

        vector<int> ans;

        for(auto it : sortVec){
          
            if(k){
                ans.push_back(it.first);
                k--;
            }  
        }

        return ans;
    }
};
