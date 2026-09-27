class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> hash;
        for(auto it : tasks){
            hash[it]++;
        }

        // priority_queue to send highest freq task to CPU
        priority_queue<int> pq;
        for(auto it : hash){
            pq.push(it.second);            
        }       

        // waiting queue -> {task, time}
        queue<pair<int,int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()){
            
            time++;

            if(!pq.empty()){
                int task = pq.top();                
                pq.pop();

                // Done one unit task                
                task--;

                // push task if has and push time with cooling n'th gaps
                if(task > 0){
                    q.push({task, time + n});
                }
            }

            // See if any task complete its waiting period          
            if(!q.empty() && q.front().second == time){                
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
