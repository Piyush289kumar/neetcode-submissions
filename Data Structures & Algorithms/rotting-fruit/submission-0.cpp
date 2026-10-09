class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();        

        // Queue -> {row, col}, curr_time
        queue<pair<pair<int,int>,int>> q;
        
        // Fresh oranges count
        int fresh_oranges = 0;

        // Add rotten oranges with curr_time = 0.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                // rotten oranges
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                // fresh oranges
                else if(grid[i][j] == 1){
                    fresh_oranges++;
                }
            }
        }        

        int time = 0;

        // 4 way movements
        vector<int> row_movements = {-1, 0, 1, 0};
        vector<int> col_movements = {0, 1, 0, -1};

        while(!q.empty()){
            auto record = q.front();
            q.pop();

            int row = record.first.first;
            int col = record.first.second;
            int curr_time = record.second;

            time = max(time, curr_time);

            for(int i=0; i<4; i++){
                int nRow = row + row_movements[i];
                int nCol = col + col_movements[i];

                // if we found is fresh orange
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] ==  1){
                    grid[nRow][nCol] = 2;
                    q.push({{nRow, nCol}, curr_time + 1});

                    // Fresh orange -> Rotten orange
                    fresh_oranges--;
                }
            }
        }

        // if there is fresh orange then return -1
        if(fresh_oranges > 0) return -1;

        return time;
    }
};
