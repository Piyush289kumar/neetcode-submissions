class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();

        if(s2.size() < k) return false;

        vector<int> s1Freq(26,0), s2Freq(26,0);

        // store s1 freqs
        for(int i=0; i<s1.size(); i++){
            s1Freq[s1[i] - 'a']++;
        }

        int l = 0;

        for(int r=0; r<s2.size(); r++){

            s2Freq[s2[r] - 'a']++;

            if((r-l+1) > k){
                s2Freq[s2[l] - 'a']--;
                l++;
            }

            if(s1Freq == s2Freq && (r-l+1) == k){
                return true;
            }

        }

        return false;

    }
};
