class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({{i,j},0});
            }
        }
        int time = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> front = q.front();
            q.pop();
            int row = front.first.first;
            int col = front.first.second;
            int t = front.second;
            time = max(time,t);
            if(col+1 < m && grid[row][col+1] == 1){
                grid[row][col+1] = 2;
                q.push({{row,col+1},t+1});
            }
            if(col-1 >= 0 && grid[row][col-1] == 1){
                grid[row][col-1] = 2;
                q.push({{row,col-1},t+1});
            }
            if(row-1 >= 0 && grid[row-1][col] == 1){
                grid[row-1][col] = 2;
                q.push({{row-1,col},t+1});
            }
            if(row+1 < n && grid[row+1][col] == 1){
                grid[row+1][col] = 2;
                q.push({{row+1,col},t+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
