class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> hash;
        for(auto it : tasks){
            hash[it]++;
        }

        priority_queue<int> pq;
        // insert task with these frequences/operation counts
        for(auto it : hash){
            pq.push(it.second);
        }

        // Create Waiting/Cool down queue
        queue<pair<int,int>> q;

        // Unit Time
        int time = 0;

        while(!pq.empty() || !q.empty()){
            time++;

            // check any task is ready then do that            
            if(!pq.empty()){
                int task_count = pq.top();
                pq.pop();

                task_count--;
                
               if(task_count > 0){
                    // {remaing unit task, curr time + n gaps}
                    q.push({task_count, time + n});
               }
            }

            // Check if any task complete its waiting/cooling periods
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
