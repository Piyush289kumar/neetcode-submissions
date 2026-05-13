class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // init all chars
        for(auto &word : words){
            for(auto &ch : word){
                indegree[ch] = 0;
            }
        }

        int n = words.size();

        // Build Graph and Indegree
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(), s2.size());
            bool found = false; // flag for no valid found

            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    indegree[s2[j]]++;
                    found = true;
                    break;
                }
            }

            // Check if Not Vaild
            if(!found && s1.size() > s2.size()) return "";            

        }

        // Push All 0 indegree Nodes in queue
        queue<char> q;

        for(auto &it : indegree){
            if(it.second == 0) q.push(it.first);
        }

        // Topo Sort
        string ans;

        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans += node;

            for(auto &it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }

        // validate topo sort lenght
        if(ans.size() != indegree.size()) return "";

        return ans;
    }
};
















