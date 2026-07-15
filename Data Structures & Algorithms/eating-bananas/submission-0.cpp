class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int l = 1, hi = 0 ;

        for(int &n : piles) hi = max(hi, n);
        
        while( l < hi){
            int mid = l + (hi - l) / 2;            

            double div_sum = 0;

            for(int i=0; i<piles.size(); i++){
                div_sum += ceil((double)piles[i] / mid);
            }

            if(div_sum <= h){
                hi = mid;
            }else{
                l = mid + 1;
            }
        }

        return hi;
    }
};
