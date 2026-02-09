class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if(r<0 ||r>=grid.size() || c<0 || c>=grid[0].size() || vis[r][c]==true || grid[r][c] == '0') return;
        vis[r][c] = true;
        dfs(r-1,c,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c-1,grid,vis);
        dfs(r,c+1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        vector<vector<bool>> visited(x,vector<bool>(y,false));
        int count = 0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(i,j,grid,visited);
                    
                    count++;
                }
            }
        }
        return count;
    }
};
