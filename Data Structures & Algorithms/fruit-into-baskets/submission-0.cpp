class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> hash;
        int l=0, mxLen = 0;

        for(int r=0; r<fruits.size(); r++){
            hash[fruits[r]]++;

            if(hash.size() > 2){
                hash[fruits[l]]--;
                if(hash[fruits[l]] == 0) hash.erase(fruits[l]);
                l++;
            }

            mxLen = max(mxLen, r-l+1);
        }

        return mxLen;
    }
};