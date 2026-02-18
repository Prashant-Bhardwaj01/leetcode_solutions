class Solution {
public:
    void bfs(vector<vector<int>>& grid,int r,int c,int m, int n){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0;
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int nr = front.first;
            int nc = front.second;
            if(nr-1 >= 0 && grid[nr-1][nc] == 1){
                grid[nr-1][nc] = 0;
                q.push({nr-1,nc});
            }
            if(nr+1 < m && grid[nr+1][nc] == 1){
                grid[nr+1][nc] = 0;
                q.push({nr+1,nc});
            }
            if(nc-1 >= 0 && grid[nr][nc-1] == 1){
                grid[nr][nc-1] = 0;
                q.push({nr,nc-1});
            }
            if(nc + 1 < n && grid[nr][nc+1] == 1){
                grid[nr][nc+1] = 0;
                q.push({nr,nc+1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1) bfs(grid,0,i,m,n);
            if(grid[m-1][i] == 1) bfs(grid,m-1,i,m,n);
        }
        
        for(int i =0;i<m;i++){
            if(grid[i][0] == 1) bfs(grid,i,0,m,n);
            if(grid[i][n-1] == 1) bfs(grid,i,n-1,m,n);
        }
        
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) c++;
            }
        }
        return c;
    }
};
