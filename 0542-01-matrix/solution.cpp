class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) {
                    q.push({0,{i,j}});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            int d = front.first;
            int nr = front.second.first;
            int nc = front.second.second;

            q.pop();
            if(nr-1 >=0 && mat[nr-1][nc] == 1 && dist[nr-1][nc]==-1){
                dist[nr-1][nc] = d + 1;
                q.push({d + 1,{nr-1,nc}});
            }
            if(nr+1 <n && mat[nr+1][nc] == 1 && dist[nr+1][nc] == -1){
                dist[nr+1][nc] = d + 1;
                q.push({d + 1,{nr+1,nc}});
            }
            if(nc-1 >=0 && mat[nr][nc-1] == 1 && dist[nr][nc-1] == -1){
                dist[nr][nc-1] = d + 1;
                q.push({d + 1,{nr,nc-1}});
            }
            if(nc+1 <m && mat[nr][nc+1] == 1 && dist[nr][nc+1] == -1){
                dist[nr][nc+1] = d + 1;
                q.push({d+1,{nr,nc+1}});
            }
        }
        return dist;
    }
};
