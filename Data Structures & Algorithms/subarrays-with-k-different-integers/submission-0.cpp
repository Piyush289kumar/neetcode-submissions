class Solution {
public:
    int countAtMostK(vector<int> &arr, int k){
        if(k < 0) return 0;
        
        int l = 0, cnt = 0;
        unordered_map<int,int> hash;
        
        for(int r=0; r<arr.size(); r++){
            hash[arr[r]]++;
            
            while(hash.size() > k){
                hash[arr[l]]--;
                if(hash[arr[l]] == 0) hash.erase(arr[l]);
                l++;
            }
            
            cnt += (r-l+1);
        }
        
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k-1);
    }
};