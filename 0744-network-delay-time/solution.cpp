class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<vector<pair<int,int>>> adj(n+1);

        for(vector<int> i : times){
            int u = i[0];
            int v = i[1];
            int times = i[2];
            adj[u].push_back({v,times});
        }

        vector<int> dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k] = 0;
        int mx = 0;
        while(!pq.empty()){
            pair<int,int> front = pq.top();
            int wt = front.first;
            int node = front.second;
            pq.pop();
            for(auto nbr: adj[node]){
                int nbr_node = nbr.first;
                int nbr_wt = nbr.second;
                if(wt + nbr_wt < dist[nbr_node]){
                    dist[nbr_node] = wt+nbr_wt;
                    
                    pq.push({dist[nbr_node],nbr_node});
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            mx = max(mx,dist[i]);
        }
        
        
        return mx;
    }
};
