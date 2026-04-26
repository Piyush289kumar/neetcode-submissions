class Solution {
public:
   void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis,
            vector<pair<int,int>>& res, int& n, int& m){
        vis[row][col] = 1;
        res.push_back({row,col});
        
       
        vector<int> rowIdx = {-1,0,1,0};
        vector<int> colIdx = {0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nRow = row + rowIdx[i];
            int nCol = col + colIdx[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                    
                    res.push_back({nRow-row, nCol-col});
                    
                    dfs(nRow, nCol, grid, vis, res, n, m);
                }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    vector<pair<int,int>> res;
                    dfs(i,j,grid,vis,res,n,m);
                    st.insert(res);
                }
            }
        }

        int cnt = 0;
        for(auto c : st){
            cnt++;
        }   
        
        return cnt;
    }
};
