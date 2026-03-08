class Solution {
public:
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long,long>>> adjList(n);
        for(auto i: roads){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> count(n,0);
        count[0] = 1;

        dist[0]= 0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<long long ,int> top = pq.top();
            long long wt = top.first;
            int node = top.second;
            pq.pop();
            if(dist[node]<wt) continue;
            for(auto nbr: adjList[node]){
                int nbr_node = nbr.first;
                int nbr_wt = nbr.second;
                if(dist[nbr_node] > wt+nbr_wt){
                    dist[nbr_node] = (wt+nbr_wt);
                    count[nbr_node] = count[node];
                    pq.push({dist[nbr_node], nbr_node});
                }else if(wt+nbr_wt==dist[nbr_node]){
                    count[nbr_node] = (count[nbr_node]+count[node])%MOD;
                }
            }
        }
        return count[n-1];
    }
};
