class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit = 0;

    KthLargest(int k, vector<int>& nums) {
        limit = k;

        for(int n : nums){
            pq.push(n);

            if(pq.size() > limit) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > limit) pq.pop();
        return pq.top();
    }
};
