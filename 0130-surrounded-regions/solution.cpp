class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][m-1] == 'O') q.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O') q.push({0,i});
            if(board[n-1][i] == 'O') q.push({n-1,i});
        }
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            pair<int,int> front = q.front();
            int r = front.first;
            int c = front.second;
            board[r][c] = 'a';
            q.pop();
            for(auto i : dir){
                int nr = r+i[0];
                int nc = c+i[1];
                if(nr>=0 && nr<n && nc>=0 && nc < m && board[nr][nc] == 'O'){
                    board[nr][nc] = 'a';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'a') board[i][j] = 'O';
            }
        }
    }
};
