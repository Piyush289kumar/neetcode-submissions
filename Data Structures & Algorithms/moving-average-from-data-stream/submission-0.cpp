class MovingAverage {
public:
    queue<int> q;
    int window_size;
    double window_sum;

    MovingAverage(int size) {
        window_size = size;
    }
    
    double next(int val) {
        q.push(val);
        window_sum += val;

        if(q.size() > window_size){
            window_sum -= q.front();
            q.pop();
        }

        return window_sum / q.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
