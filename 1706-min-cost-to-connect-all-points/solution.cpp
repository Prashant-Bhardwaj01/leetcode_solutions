class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = (abs(x1-x2) + abs(y1-y2));
                graph[i].push_back({j,wt});
                graph[j].push_back({i,wt});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n,false);
        pq.push({0,0});
        int cost = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int wt = top.first;
            int node = top.second;
            if(!visited[node]){
                visited[node] = true;
                cost += wt;
                for(auto nbr:graph[node]){
                    int nbr_node = nbr.first;
                    int nbr_wt = nbr.second;
                    if(!visited[nbr_node]) pq.push({nbr_wt,nbr_node});
                }
            }
        }
        return cost;

    }
};
