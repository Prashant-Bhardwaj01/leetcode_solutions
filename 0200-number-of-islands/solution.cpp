class Solution {
public:
    void dfs(int r,int c, int n, int m, vector<vector<char>>& grid){
        if(r<0 || r>n-1 || c<0 || c>m-1 || grid[r][c] == '0') return ;
        grid[r][c] = '0';
        dfs(r-1,c,n,m,grid);
        dfs(r+1,c,n,m,grid);
        dfs(r,c-1,n,m,grid);
        dfs(r,c+1,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
