class Solution {
public:

        int dp[51][51][51][51] ;
    // void dfs1(vector<vector<int>>& grid, int r, int c, int & ans){
    //     if(r==grid.size() || c == grid.size()) return ;
    //     if(grid[r][c] == -1) return ;
    //     if(r==grid.size()-1 && c==grid.size()-1) {
    //         ans+=grid[r][c];
    //         return ;
    //     }
    //     ans+=grid[r][c];
    //     grid[r][c] = 0;
    //     dfs1(grid,r+1,c,ans);
    //     dfs1(grid,r,c+1,ans);
    // }
    // void dfs2(vector<vector<int>>& grid, int r, int c, int & ans){
    //     if(r<0 || c<0) return ;
    //     if(r==0 && c==0){ 
    //         ans+= grid[r][c];
    //         return;
    //     }
    //     if(grid[r][c] == -1) return ;
    //     ans+=grid[r][c];
    //     grid[r][c] = 0;
    //     dfs2(grid,r-1,c,ans);
    //     dfs2(grid,r,c-1,ans);
    // }
    int dfs(int r1,int c1, int r2,int c2,vector<vector<int>>& grid, int n){

        if(r1 >= n || c1 >= n || r2 >=n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        int cherry =0;
        if(r1==n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1) return dp[r1][c1][r2][c2] = cherry+grid[r1][c1];
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        if(r1 == r2 && c1 == c2){
            cherry+= grid[r1][c1]; 
        }else{
            cherry+= grid[r1][c1]+grid[r2][c2];  
        }
        int l = dfs(r1,c1+1,r2,c2+1,grid,n);
        int r = dfs(r1+1,c1,r2+1,c2,grid,n);
        int u = dfs(r1+1,c1,r2,c2+1,grid,n);
        int d = dfs(r1,c1+1,r2+1,c2,grid,n);
        int ans= max(max(l,r),max(u,d));
        return dp[r1][c1][r2][c2]=cherry +ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // if(grid[0][0] == -1 && grid[n-1][n-1] == -1) return 0;
        // int ans1=0;
        // dfs1(grid, 0,0,ans1);
        // int ans2 = 0;
        // dfs2(grid, n-1,n-1,ans2);
        // dfs(grid,0,0);
        // return ans1+ans2;
        memset(dp,-1,sizeof(dp));
        return max(0,dfs(0,0,0,0,grid,n));
    }
};
