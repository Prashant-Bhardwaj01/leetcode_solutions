class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        for(auto& road : roads){
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }
        vector< long long > dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            if(d > dist[node]) continue;
            for(auto [neighbor ,weight] : graph[node]){
                long long nd = d+weight;
                if(nd < dist[neighbor]){
                    dist[neighbor] = nd;
                    ways[neighbor] = ways[node];
                    pq.push({nd, neighbor});
                }else if(nd == dist[neighbor]){
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
}; 
