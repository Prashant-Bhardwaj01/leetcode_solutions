class Solution {
public:
    int ans = 0;
    int dfs(int r, int c,vector<vector<int>>& grid, int n, int m){
        if(r<0 || c<0 || r>= n || c>= m || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        
        int sum= 1 + dfs(r+1,c,grid,n,m) + dfs(r,c+1,grid,n,m) + dfs(r-1,c,grid,n,m) +  dfs(r,c-1,grid,n,m);
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ans = max(ans,dfs(i,j,grid,n,m));
                }
            }
        }
        return ans;
    }
};
