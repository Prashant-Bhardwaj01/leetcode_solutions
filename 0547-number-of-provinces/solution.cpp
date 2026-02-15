class Solution {
public:
    void bfs(int src,vector<vector<int>>& isConnected, vector<bool>& visited){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[front][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int c=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                bfs(i,isConnected,visited);
            }
        }
        return c;
        
    }
};
