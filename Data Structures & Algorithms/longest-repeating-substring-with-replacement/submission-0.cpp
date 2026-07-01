class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int mxlen = 0, mxFreq = 0;

        int l = 0;
        for(int r=0; r<s.size(); r++){

            freq[s[r] - 'A']++;

            mxFreq = max(mxFreq, freq[s[r] - 'A']);

            while((r-l+1) - mxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            if((r-l+1) - mxFreq <= k){
                mxlen = max(mxlen, (r-l+1));
            }

        }

        return mxlen;
    }
};
